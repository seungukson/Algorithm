#include <iostream>
#include <queue>
using namespace std;

const int MAX = 11;
int M, C;
int message[MAX];
int m_idx = 0;
int consumer[MAX];
bool isDone()
{
	for (int i = 0; i < C; i++)
	{
		if (consumer[i] > 0) return false;
	}
	return true;
}
int main(void) {
	int ans = 0;
	scanf("%d %d", &M, &C);
	for (int i = 0; i < M; i++)
	{
		scanf("%d ", &message[i]);
	}
	for (int i = 1; i < 1001; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (consumer[j] == 0 && m_idx < M) //ť�� �� �Ҵ���� �ʾҰ�, ť�� ���������
			{
				consumer[j] = message[m_idx]; //�Ҵ��ϱ�
				m_idx++;
			}

			if (consumer[j] != 0)  //ť�� ������� �ʴٸ�
			{
				consumer[j]--;
			}
		}

		if (m_idx >= M && isDone())
		{
			ans = i;
			break;
		}
	}
	printf("%d ", ans);
	return 0;
}