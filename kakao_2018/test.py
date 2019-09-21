import requests
import numpy as np
import json

max_size = 3000

url = 'https://wqwfrkh5k1.execute-api.ap-northeast-2.amazonaws.com/kakao-2020/'
auth = '537c47d93164d700cb4631c374da2a25'
book =[]
idx = {}
main_phone = {}
main_follow = {}
is_follow = [[0]*max_size for i in range(max_size)]
total_count = 0
tp_m = 3000
add_m = 3000

def is_user(num):
    if(num in book) :
        return True
    return False
def select_for_recommendations(): #json의 배열을 리턴 : [{'id':"", recommend:[] },{} ...]
    large_arr = []
    global tp_m
    print("tp_m:",tp_m)
    total_count = 0
    for user in users['users']:
        my_count = 0
        tmp_dict = {}
        if len(main_follow[user['user']]) >= 20: # 팔로우 20명 넘으면 넘김
            continue
        # print("아직 안된사람의 팔로우수: ",len(main_follow[user['user']]))
        tmp_dict['user'] = user['user']
        tmp_dict['recommendation'] = []
        for ph in user['phone']: #전화번호부 돈다
            # print(ph)
            if is_user(ph)==False:  #회원이 아니면 넘긴다.
                continue
            if is_follow[idx[user['user']]][idx[ph]] == 0: #팔로우가 아니라면 추가
                tmp_dict['recommendation'].append(ph)
                total_count += 1
                my_count+=1
                if my_count>=10 or total_count>=tp_m :
                    break
            if(my_count>=10 or total_count>=tp_m):
                break
        if my_count<10 and total_count <tp_m :
            for ph in user['phone']: #다시한번 전화번호부 돈다
                if is_user(ph)==False: #회원이 아니면 넘긴다.
                    continue
                for newone in main_follow[ph]: #전화번호부 등록된사람의 팔로우목록을 돈다
                    if is_user(newone)==False: # 전화부 등록된사람이 팔로우한 사람이 회원이 아니면 넘긴다.
                        continue
                    if is_follow[idx[user['user']]][idx[newone]] ==0:
                        tmp_dict['recommendation'].append(newone)
                        my_count+=1
                        total_count+=1
                        if my_count >=10 or total_count>=tp_m:
                            break
                if my_count>=10 or total_count>=tp_m:
                    break

        if my_count < 10 and total_count < tp_m :
            for numb in book: # 전번 없는애들
                if numb!=user['user'] and is_follow[idx[user['user']]][idx[numb]]==0:
                    tmp_dict['recommendation'].append(numb)
                    my_count+=1
                    total_count+=1
                    if my_count>=10 or total_count >= tp_m:
                        break

        large_arr.append(tmp_dict)
        # print(large_arr)
        if(total_count >= tp_m):
            break
    return large_arr


def start(problem):  # token, day, problem 이 발급
    uri = url + 'start'
    # + '/' + user + '/' + str(problem) + '/' + str(count)

    return requests.post(uri, headers={'X-Auth-Token': auth}, json={'problem': problem}).json()


def users(token):  # user정보 : 전체사용자의 목록과 전화번호부 반환, day, page, size, total, users(obj-user, following, phone)의 배열
    # 예시1: size: 10, page: 1 인 경우 -> 0~9번 사용자의 list가 반환 된다.
    uri = url + 'users'
    return requests.get(uri, headers={'Authorization': token}).json()


def new_users(token):  # 신규가입user정보 : day, new_users(obj-user, phone)이ㅡ 배열
    uri = url + 'new_users'
    return requests.get(uri, headers={'Authorization': token}).json()

def recommend(token, recommend):  #recommend: 'recommendations': obj({user(전화번호),recommendataion(추천전화번호배열)})의 배열
    uri = url + 'recommend'

    return requests.post(uri, headers={'Authorization': token}, json={'recommendations': recommend}).json()

def run(token):
    uri = url +'run_simulation'
    return requests.put(uri, headers = {'Authorization':token}).json()

def status(token):
    uri = url + 'status'
    return requests.get(uri, headers={'Authorization': token}).json()

def get_score(token):
    uri = url+'score'
    return requests.get(uri, headers = {'Authorization':token}).json()

def init(users):
    main_phone.clear()
    main_follow.clear()
    for user in users['users']:
        main_phone[user['user']] = []
        main_follow[user['user']] = []
        for ph in user['phone']:
            main_phone[user['user']].append(ph)
        for fol in user['following']:
            main_follow[user['user']].append(fol)
            is_follow[idx[user['user']]][idx[fol]] = 1;


def init_book_idx(users):
    book.clear()
    for user in users['users']:
        book.append(user['user'])
    for i, num in enumerate(book):
        idx[num] = i

def add_new(new_users):
    for new_user in new_users['new_users']:
        book.append(new_user['user'])
        idx[new_user['user']] = len(book)-1
        main_phone[new_user['user']] = []
        main_follow[new_user['user']] = []
        for ph in new_user['phone']:
            main_phone[new_user['user']].append(ph)


def p0_simulator():
    problem = 2
    ret = start(problem)
    token = ret['token']

    print('Token is %s', ret['token'])


    for i in range(100100):

        us = users(token)
        # print('users:%s' % us)
        init(us)
        # if(i==0):
        init_book_idx(us)

        # 2번문제만 필요
        new_us = new_users(token)
        print('new_users:%s' % new_us)
        add_new(new_us)


        recommendataion = select_for_recommendations()
        print("recomm : %s" % recommendataion)
        rec = recommend(token, recommendataion)

        print("rec response: %s" % rec)
        r = run(token)
        if( i >= 31):
            global tp_m
            tp_m = 4090
        # if(i>=2 and i<=30):
        #     global add_m, tp_m
        #     add_m = add_m // 30
        #     tp_m = tp_m + add_m
        #     add_m = 3000 - add_m
        #     print("add_m:%d  tp_m:%d "%(add_m, tp_m))
        # print('run :%s' % r)
        sc = get_score(token)
        print('score:%s' % sc)
        s = '.'

        # break
        while(1):
            stat = status(token)
            if(stat['status']=='working'):
                continue
            if(stat['status']=='done'):
                break
            if(stat['status']=='finish'):
                s = 'finish'
                break

        # print("is_follow: " , is_follow)
        if s=='finish':
            break

    # print('Token is %s' % token)
    # print("엘베 time: %d 엘베상태:%s" % (ret['timestamp'], ret['elevators']))

    # oc = oncalls(token)
    # a= []
    # a.append()
    # print(oc)
    # while not oc['is_end']:
    #     if len(oc['calls'])!=0:
    #         for dic in oc['calls']:
    #             dic['id']


# #0
#     oc = oncalls(token)
#     print(oc)
#     action(token, [{'elevator_id': 0, 'command': 'UP'}, {'elevator_id': 1, 'command': 'STOP'}])

if __name__ == '__main__':
    p0_simulator()
