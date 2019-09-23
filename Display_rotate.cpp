#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 110;
char* matrix[MAX][MAX];
int N, W;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

vector<char*> get_line(int t, int k)//t번째 테두리를 뽑아내서 k번 돌린 후 배열로 저장
{
	vector<char*> arr;
	int start = (N-t)/2;
	int end = N-1-start;

	if(start ==end)
	{
		arr.push_back(matrix[start][start]);
		return arr;
	}
	int dir = 0;
	int x = start;
	int y = start;
	do
	{
		arr.push_back(matrix[x][y]);
		
		int nx = x+dx[dir];
		int ny = y+dy[dir];
		if(nx>end || nx<start ||ny >end ||ny<start)
		{
			dir++;
			nx = x+dx[dir];
			ny = y+dy[dir];
		}
		x = nx;
		y = ny;
	}
	while(x!=start || y!=start);

	// k만큼 회전
	//시계방향이면 밀고, 반시계면 당긴다.
	int size = arr.size();
	
	vector<char*> ret;
	ret.resize(size);
	for(int i=0; i<size; i++)
	{
		int pos = (i-k)%size;
		if(pos<0)
		{
			pos = pos+size;
		}
		ret[i] = arr[pos];
	}
	return ret;
}

void put_line(vector<char*> vec, int t)
{
	vector<char*> arr;
	int start = (N-t)/2;
	int end = N-1-start;
	if(start==end) return;
	
	int idx = 0;
	
	int dir = 0;
	int x = start;
	int y = start;
	do
	{
		matrix[x][y] = vec[idx++];
		
		int nx = x+dx[dir];
		int ny = y+dy[dir];
		if(nx>end || nx<start ||ny >end ||ny<start)
		{
			dir++;
			nx = x+dx[dir];
			ny = y+dy[dir];
		}
		x = nx;
		y = ny;
	}
	while(x!=start || y!=start);

	return;
}

void rotate(int t, int k)//matrix의 n번재 테두리를 k 만큼 돌리는 함수
{
	if(t<(N/2))
		return;
	vector<char*> vec(2*t+2*(t-2));
	vec = get_line(t, k); //t번째 테두리를 뽑아내서 배열로 저장

	put_line(vec, t); //t번째 테두리를 vec으로 채워넣기
		
	rotate(t-2, -1*k);
}

int main() {
	scanf("%d %d ", &N, &W);	
	char str[MAX][2010];
	
	for(int i=0; i<N; i++)
	{		
		cin.getline(str[i],2010);
		char* tok1 = strtok(str[i]," ");
		int idx = 0;
		
		while(tok1!=0)
		{
			matrix[i][idx++] = tok1;		
			tok1 = strtok(NULL," ");
		}
	}
	
	rotate(N, W);
	for(int i =0; i<N; i++)
	{
		for(int j = 0; j<N; j++)
		{
			printf("%s ",matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}