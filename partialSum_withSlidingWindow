#include <stdio.h>
using namespace std;
const int MAX = 200010;
int ans;
int n;
int partialsum;

int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	int tc;
	scanf("%d",&tc);
	for (int t = 1; t <= tc; t++)
	{
		scanf("%d", &n);
		int num;
		partialsum = 0;
		scanf("%d", &num);
		ans = num;
		int tmpmax = num;
		for (int i = 1; i < n; i++)
		{
			scanf("%d", &num);
			if (partialsum + num < 0)
			{
				ans = max(ans, partialsum);
				partialsum = 0;
			}
			else
			{
				partialsum += num;
                ans = max(ans, partialsum);
			}
			if (tmpmax < 0) tmpmax = max(tmpmax, num);
		}
		ans = max(ans, partialsum);
		if (tmpmax < 0) ans = tmpmax;
		printf("#%d %d\n", t, ans);
	}
	return 0;
}
