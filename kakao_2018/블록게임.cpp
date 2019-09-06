#include <string>
#include <vector>

using namespace std;
bool isA(int x, int y, vector<vector<int>>* board)
{
	int N = board->size();
	if (x - 1 < 0 || y + 2 >= N) return false;
	int t = (*board)[x][y];
	if ((*board)[x][y + 1] == t && (*board)[x][y + 2] == t && (*board)[x - 1][y + 1] == t)
	{
		for (int i = x - 1; i >= 0; i--)
		{
			if ((*board)[i][y + 2])
				return false;
		}
		(*board)[x][y] = (*board)[x][y + 1] = (*board)[x][y + 2] = (*board)[x - 1][y + 1] = 0;
		return true;
	}
	return false;
}
bool isB(int x, int y, vector<vector<int>>* board)
{
	int N = board->size();
	if (x - 2 < 0 || y - 1 < 0) return false;
	int t = (*board)[x][y];
	if ((*board)[x][y - 1] == t && (*board)[x - 1][y - 1] == t && (*board)[x - 2][y - 1] == t)
	{
		(*board)[x][y] = (*board)[x][y - 1] = (*board)[x - 1][y - 1] = (*board)[x - 2][y - 1] = 0;
		return true;
	}
	return false;
}
bool isC(int x, int y, vector<vector<int>>* board)
{
	int N = board->size();
	if (x - 1 < 0 || y + 2 >= N) return false;
	int t = (*board)[x][y];
	if ((*board)[x][y + 1] == t && (*board)[x][y + 2] == t && (*board)[x - 1][y + 2] == t)
	{
		for (int i = x - 1; i >= 0; i--)
		{
			if ((*board)[i][y + 1])
				return false;
		}
		(*board)[x][y] = (*board)[x][y + 1] = (*board)[x][y + 2] = (*board)[x - 1][y + 2] = 0;
		return true;
	}
	return false;
}
bool isD(int x, int y, vector<vector<int>>* board)
{
	int N = board->size();
	if (x - 1 < 0 || y - 1 < 0 || y + 1 >= N) return false;
	int t = (*board)[x][y];
	if ((*board)[x][y + 1] == t && (*board)[x][y - 1] == t && (*board)[x - 1][y - 1] == t)
	{
		for (int i = x - 1; i >= 0; i--)
		{
			if ((*board)[i][y + 1])
				return false;
		}
		(*board)[x][y] = (*board)[x][y + 1] = (*board)[x][y - 1] = (*board)[x - 1][y - 1] = 0;
		return true;
	}
	return false;
}
bool isE(int x, int y, vector<vector<int>>* board)
{
	int N = board->size();
	if (x - 2 < 0 || y + 1 >= N) return false;
	int t = (*board)[x][y];
	if ((*board)[x][y + 1] == t && (*board)[x - 1][y + 1] == t && (*board)[x - 2][y + 1] == t)
	{
		(*board)[x][y] = (*board)[x][y + 1] = (*board)[x - 1][y + 1] = (*board)[x - 2][y + 1] = 0;
		return true;
	}
	return false;
}
int solution(vector<vector<int>> board) {
	int N = board.size();
	int i = 0;
	int cnt = 0;
	while (i < N)
	{
		int x = 0;
		int y = i;
		int bottom = 0;
		while (!board[x][y])
		{
			x++;
			if (x == N)
			{
				bottom = 1;
				break;
			}
		}
		if (bottom)
		{
			i++;
			continue;
		}
		if (isA(x, y, &board) || isB(x, y, &board) || isC(x, y, &board) || isD(x, y, &board) || isE(x, y, &board))
		{
			cnt++;
			x = y = 0;
			i = 0;
			continue;
		}
		i++;
	}
	return cnt;
}