uid = []
do = []
nick = {}
def solution(record) :
	answer = []
	for rec in record :
arg = rec.split()
if (arg[0] == "Enter") :
	uid.append(arg[1])
	do.append(0)
		nick[arg[1]] = arg[2]
		elif(arg[0] == "Change") :
		nick[arg[1]] = arg[2]
else:#leave
do.append(1)
uid.append(arg[1])

for i, (Uid, Do) in enumerate(zip(uid, do)) :
	if (Do == 0) :
		answer.append(nick[Uid] + "님이 들어왔습니다.")
	else :
		answer.append(nick[Uid] + "님이 나갔습니다.")
		return answer