#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
const int MAX = 510;
using namespace std;
struct mystruc {
	float idx;
	float cnt = 0;
	float per = 0;
	bool operator >(mystruc A)
	{
		if (this->per == A.per)
		{
			if (this->idx == 0) return false;
			else if (A.idx == 0) return true;
			else return this->idx < A.idx;
		}
		return this->per > A.per;
	}
};
bool comp(mystruc A, mystruc B)
{
	return A > B;
}
vector<mystruc> my_struc;

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	my_struc.resize(N + 2);
	for (int i = 0; i <= N + 1; i++)
	{
		my_struc[i].idx = i;
	}

	for (int i = 0; i < stages.size(); i++)
	{
		my_struc[stages[i]].cnt++;
	}
	float tmp = 0;
	for (int i = N + 1; i >= 0; i--)
	{
		tmp += my_struc[i].cnt;
		printf("tmp:%.3f\n", tmp);
		if (tmp == 0)
			continue;
		my_struc[i].per = my_struc[i].cnt / tmp;
	}
	for (int i = 0; i <= N + 1; i++)
	{
		printf("idx:%.0f  cnt:%.0f  per:%.3f\n", my_struc[i].idx, my_struc[i].cnt, my_struc[i].per);
	}
	sort(my_struc.begin(), my_struc.end() - 1, comp);
	for (int i = 0; i < my_struc.size(); i++)
	{
		printf("i:%d  idx:%.0f per:%.3f\n", i, my_struc[i].idx, my_struc[i].per);
	}
	for (int i = 0; i < N; i++)
		answer.push_back(my_struc[i].idx);
	return answer;
}