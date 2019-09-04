#include <string>
#include <vector>
#include <stdio.h>
#include <map>
#include <algorithm>
const int MAX = 10;
using namespace std;

int ans = 0;
int cand[MAX];
map<string, int> cnt;
vector<vector<int>> vecarr;
void comb(vector<vector<string>> rel, int idx, int now, int lim)
{
	cnt.clear();
	int flag = 0;
	for (int i = 0; i < rel.size(); i++)
	{
		string tmp = "";
		for (int j = 0; j < idx; j++)
		{
			tmp += '.';
			tmp += rel[i][cand[j]];
		}
		if (cnt.count(tmp) == 0)
		{
			cnt[tmp] = 1;
		}
		else // 키 있음
		{
			flag = 1;
			break;
		}
	}//다 통과했으면
	if (flag == 0)
	{
		vector<int> tmp;
		for (int i = 0; i < idx; i++)
		{
			tmp.push_back(cand[i]);
			//printf("%d ", cand[i]);
		}
		vecarr.push_back(tmp);
		//printf("\n");
		ans++;
		return;
	}
	for (int i = now; i < lim; i++)
	{
		cand[idx] = i;
		comb(rel, idx + 1, i + 1, lim);
	}
}
bool comp(vector<int> a, vector<int> b)
{
	return a.size() < b.size();
}
int solution(vector<vector<string>> relation) {
	int col = relation[0].size();
	comb(relation, 0, 0, col);
	sort(vecarr.begin(), vecarr.end(), comp);

	vector<int> delarr;
	delarr.resize(vecarr.size());
	for (int i = 0; i < vecarr.size(); i++)
	{
		for (int j = i + 1; j < vecarr.size(); j++)
		{
			vector<int>::iterator itr = vecarr[i].begin();
			for (int k = 0; k < vecarr[j].size(); k++)
			{

				if (*itr == vecarr[j][k])
				{
					itr++;
					if (itr == vecarr[i].end())
					{
						delarr[j]++;
						break;
					}
				}
			}
		}
	}
	int c = 0;
	for (int i = 0; i < delarr.size(); i++)
	{
		if (delarr[i] == 0) c++;
		printf("%d ", delarr[i]);
	}
	printf("\n");

	for (int i = 0; i < vecarr.size(); i++)
	{
		for (int j = 0; j < vecarr[i].size(); j++)
		{
			printf("%d ", vecarr[i][j]);
		}
		printf("\n");
	}
	return c;
}