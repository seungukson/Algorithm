#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct my_st {
	int idx;
	int times;
};
queue<my_st> q;
int solution(vector<int> food_times, long long k) {
	long long total = 0;
	for (int i = 0; i < food_times.size(); i++)
	{
		q.push({ i + 1,food_times[i] });
		total += food_times[i];
	}
	if (total <= k) return -1;
	sort(food_times.begin(), food_times.end());

	int a = food_times.size();
	long long sum = 0;
	int pc = 0;
	int flag = 0;
	for (int i = 0; i < food_times.size(); i++)
	{
		int s;
		if (i == 0) s = food_times[i];
		else s = food_times[i] - food_times[i - 1];
		for (int j = 0; j < s; j++)
		{
			if (sum + a > k)
			{
				flag = 1;
				break;
			}
			sum += a;
			pc++;
		}
		if (flag == 1)
			break;
		a--;
	}
	long long unt = k - sum;
	int tmp;
	int tmpidx;
	for (long long i = 0; i <= unt;)
	{
		my_st now = q.front();
		q.pop();
		now.times -= pc;
		if (now.times > 0)
		{
			tmp = now.times;
			tmpidx = now.idx;
			i++;
		}
	}
	if (tmp != 0) return tmpidx;
	else
	{
		while (!q.empty())
		{
			my_st now = q.front();
			q.pop();
			now.times -= pc;
			if (now.times > 0)
			{
				return now.idx;
			}
		}
	}
	// return q.front().idx;
//     for(long long i=0; i<k; i++)
//     {
//         my_st now = q.front();
//         q.pop();
//         now.times--;
//         if(now.times!=0)
//             q.push(now);
//         if(q.empty()) return -1;
//     }

//     int answer = 0;
//    return q.front().idx;
}