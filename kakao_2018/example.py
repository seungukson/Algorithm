import requests
import json

url = 'http://localhost:8000'


def start(user, problem, count):
    uri = url + '/start' + '/' + user + '/' + str(problem) + '/' + str(count)

    return requests.post(uri).json()


def oncalls(token):
    uri = url + '/oncalls'
    return requests.get(uri, headers={'X-Auth-Token': token}).json()


def action(token, cmds):
    uri = url + '/action'
    return requests.post(uri, headers={'X-Auth-Token': token}, json={'commands': cmds}).json()


def p0_simulator():
    user = 'tester'
    problem = 0
    count = 2

    ret = start(user, problem, count)
    token = ret['token']
    print('Token for %s is %s' % (user, token))
    print("엘베 time: %d 엘베상태:%s" % (ret['timestamp'], ret['elevators']))

#0
    oc = oncalls(token)
    print(oc)
    ac = action(token, [{'elevator_id': 0, 'command': 'UP'}, {'elevator_id': 1, 'command': 'STOP'}])
    print(ac)
#1
    oc = oncalls(token)
    print(oc)
    action(token, [{'elevator_id': 0, 'command': 'UP'}, {'elevator_id': 1, 'command': 'OPEN'}])
#2
    oc = ''
    oc = oncalls(token)
    print(oc)
    action(token, [{'elevator_id': 0, 'command': 'UP'}, {'elevator_id': 1, 'command': 'ENTER', 'call_ids': [2, 3]}])
#3
    oc = ''
    oc = oncalls(token)
    print(oc)
    action(token, [{'elevator_id': 0, 'command': 'STOP'}, {'elevator_id': 1, 'command': 'CLOSE'}])
#4
    oc = ''
    oc = oncalls(token)
    print(oc)
    action(token, [{'elevator_id': 0, 'command': 'OPEN'}, {'elevator_id': 1, 'command': 'UP'}])
#5
    oc = ''
    oc = oncalls(token)
    print(oc)
    action(token, [{'elevator_id': 0, 'command': 'ENTER', 'call_ids': [0, 1]}, {'elevator_id': 1, 'command': 'STOP'}])
    # 6
    oc = ''
    oc = oncalls(token)
    print(oc)
    action(token, [{'elevator_id': 0, 'command': 'CLOSE'}, {'elevator_id': 1, 'command': 'OPEN'}])
    # 7
    oncalls(token)
    action(token, [{'elevator_id': 0, 'command': 'DOWN'}, {'elevator_id': 1, 'command': 'EXIT', 'call_ids': [2]}])
    # 8
    oncalls(token)
    action(token, [{'elevator_id': 0, 'command': 'STOP'}, {'elevator_id': 1, 'command': 'CLOSE'}])
    # 9
    oncalls(token)
    action(token, [{'elevator_id': 0, 'command': 'OPEN'}, {'elevator_id': 1, 'command': 'UP'}])
    # 10
    oncalls(token)
    action(token, [{'elevator_id': 0, 'command': 'EXIT', 'call_ids': [1]}, {'elevator_id': 1, 'command': 'UP'}])
    # 11
    oncalls(token)
    action(token, [{'elevator_id': 0, 'command': 'CLOSE'}, {'elevator_id': 1, 'command': 'STOP'}])
    # 12
    oncalls(token)
    action(token, [{'elevator_id': 0, 'command': 'DOWN'}, {'elevator_id': 1, 'command': 'OPEN'}])
    # 13
    oncalls(token)
    action(token, [{'elevator_id': 0, 'command': 'STOP'}, {'elevator_id': 1, 'command': 'EXIT', 'call_ids': [3]}])
    # 14
    oncalls(token)
    action(token, [{'elevator_id': 0, 'command': 'OPEN'}, {'elevator_id': 1, 'command': 'CLOSE'}])
    # 15
    oncalls(token)
    action(token, [{'elevator_id': 0, 'command': 'ENTER', 'call_ids': [4]}, {'elevator_id': 1, 'command': 'STOP'}])
    # 16
    oncalls(token)
    action(token, [{'elevator_id': 0, 'command': 'CLOSE'}, {'elevator_id': 1, 'command': 'STOP'}])
    # 17
    oncalls(token)
    action(token, [{'elevator_id': 0, 'command': 'DOWN'}, {'elevator_id': 1, 'command': 'STOP'}])
    # 18
    oncalls(token)
    action(token, [{'elevator_id': 0, 'command': 'STOP'}, {'elevator_id': 1, 'command': 'STOP'}])
    # 19
    oncalls(token)
    action(token, [{'elevator_id': 0, 'command': 'OPEN'}, {'elevator_id': 1, 'command': 'STOP'}])
    # 20
    oncalls(token)
    action(token, [{'elevator_id': 0, 'command': 'EXIT', 'call_ids': [0, 4]}, {'elevator_id': 1, 'command': 'STOP'}])
    # 21
    oncalls(token)
    action(token, [{'elevator_id': 0, 'command': 'ENTER', 'call_ids': [5]}, {'elevator_id': 1, 'command': 'STOP'}])
    # 22
    oncalls(token)
    action(token, [{'elevator_id': 0, 'command': 'CLOSE'}, {'elevator_id': 1, 'command': 'STOP'}])
    # 23
    oncalls(token)
    action(token, [{'elevator_id': 0, 'command': 'UP'}, {'elevator_id': 1, 'command': 'STOP'}])
    # 24
    oncalls(token)
    action(token, [{'elevator_id': 0, 'command': 'STOP'}, {'elevator_id': 1, 'command': 'STOP'}])
    # 25
    oncalls(token)
    action(token, [{'elevator_id': 0, 'command': 'OPEN'}, {'elevator_id': 1, 'command': 'STOP'}])
    # 26
    oncalls(token)
    action(token, [{'elevator_id': 0, 'command': 'EXIT', 'call_ids': [5]}, {'elevator_id': 1, 'command': 'STOP'}])

    oncalls(token)
    action(token, [{'elevator_id': 0, 'command': 'EXIT', 'call_ids': [5]}, {'elevator_id': 1, 'command': 'STOP'}])


if __name__ == '__main__':
    p0_simulator()
