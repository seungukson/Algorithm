import re


def solution(word, pages):
    p = re.compile('(?<=<head>)[\w\W]+(?=<\/head>)')
    ps = re.compile('<meta property="og:url"\scontent="(\S+)"\/>')
    p2 = re.compile('<a href="(\S+)">')
    p3 = re.compile('(?<![a-z])' + word.lower() + '(?![a-z])')
    # p3 = re.compile(r"\b"+word.lower()+r"\b")
    address = [];
    link = [];
    b_score = [];
    come_link = []
    idx = {};
    l_score = [];
    for i, a in enumerate(pages):
        address.append(ps.findall(p.findall(pages[i])[0])[0])
        idx[ps.findall(p.findall(pages[i])[0])[0]] = i;
        link.append(p2.findall(pages[i]))
        # print(i, pages[i].lower())
        b_score.append(len(p3.findall(pages[i].lower())))
        come_link.append([])

    for i in range(0, len(pages)):
        for lik in link[i]:
            if lik in idx:
                come_link[idx[lik]].append(i)
    for i in range(0, len(pages)):
        sum = 0
        for j in come_link[i]:
            if (len(link[j]) == 0):
                continue
            sum += b_score[j] / len(link[j])
        l_score.append(sum)
    print("address", address)
    print("link", link)
    print("b_score", b_score)
    print("come_link", come_link)
    print("l_score", l_score)

    max_score = -1
    maxidx = 0
    for i in range(0, len(pages)):
        if (max_score < (l_score[i] + b_score[i])):
            maxidx = i
            max_score = l_score[i] + b_score[i]
    print("max_idx", maxidx)
    return maxidximport re

def solution(word, pages):

    p = re.compile('(?<=<head>)[\w\W]+(?=<\/head>)')
    ps = re.compile('<meta property="og:url"\scontent="(\S+)"\/>')
    p2 = re.compile('<a href="(\S+)">')
    p3 = re.compile('(?<![a-z])'+word.lower()+'(?![a-z])')
    # p3 = re.compile(r"\b"+word.lower()+r"\b")
    address = [];
    link = [];
    b_score = [];
    come_link = []
    idx = {};
    l_score =[];
    for i,a in enumerate(pages):
        address.append(ps.findall(p.findall(pages[i])[0])[0])
        idx[ps.findall(p.findall(pages[i])[0])[0]] = i;
        link.append(p2.findall(pages[i]))
        # print(i, pages[i].lower())
        b_score.append(len(p3.findall(pages[i].lower())))
        come_link.append([])

    for i in range(0,len(pages)):
        for lik in link[i]:
            if lik in idx:
                come_link[idx[lik]].append(i)
    for i in range(0,len(pages)):
        sum = 0
        for j in come_link[i]:
            if(len(link[j])==0):
                continue
            sum += b_score[j]/len(link[j])
        l_score.append(sum)
    print("address",address)
    print("link",link)
    print("b_score",b_score)
    print("come_link", come_link)
    print("l_score",l_score)

    max_score = -1
    maxidx = 0
    for i in range(0,len(pages)):
        if(max_score<( l_score[i] + b_score[i] )):
            maxidx = i
            max_score = l_score[i] + b_score[i]
    print("max_idx",maxidx)
    return maxidx