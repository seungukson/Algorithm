#include <string>
#include <vector>
#include <algorithm>
const int MAX = 10010;
using namespace std;
int adj[MAX][2];
struct my_st {
	int idx;
	vector<int>* p;
};
vector<my_st> struc;
vector<my_st*> ptr;

bool cmp(my_st* A, my_st* B)
{
	if (A->p[0][1] == B->p[0][1])
	{
		return A->p[0][0] > B->p[0][0];
	}
	return A->p[0][1] > B->p[0][1];
}
void makeTree(int leftx, int rightx, int now, int idx, vector<vector<int>> nodeinfo)//idx는 ptr배열 내에서의 순서, nodeinfo[now-1]번에 x,y좌표 들어있다.
{//다음 레벨에서 leftx보다 크고 now의 x보다 작은곳에 left가 있다. rightx보다 작고 now의 x보다 큰 곳에 right가 있다.
	if (idx >= ptr.size()) return;
	int lev_y = ptr[idx]->p[0][1];
	int t_idx = idx;

	int l = 0;
	int r = 0;
	while (t_idx < ptr.size() && ptr[t_idx]->p[0][1] == lev_y)//같은레벨을돌면서 
	{
		int nowx = ptr[t_idx]->p[0][0];
		if (leftx < nowx && nowx < nodeinfo[now - 1][0])//레프트조건만족이면 넣기
		{
			adj[now][0] = l = ptr[t_idx]->idx;
		}
		else if (nodeinfo[now - 1][0] < nowx && nowx < rightx) //라이트조건 만족이면 넣기
		{
			adj[now][1] = r = ptr[t_idx]->idx;
		}
		t_idx++;
	}
	if (l != 0) makeTree(leftx, nodeinfo[now - 1][0], l, t_idx, nodeinfo);
	if (r != 0) makeTree(nodeinfo[now - 1][0], rightx, r, t_idx, nodeinfo);
}
void preorder(int st, vector<int>* a)
{
	a->push_back(st);
	if (adj[st][0] != 0) preorder(adj[st][0], a);
	if (adj[st][1] != 0) preorder(adj[st][1], a);
}
void postorder(int st, vector<int>* a)
{
	if (adj[st][0] != 0) postorder(adj[st][0], a);
	if (adj[st][1] != 0) postorder(adj[st][1], a);
	a->push_back(st);
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	struc.resize(nodeinfo.size());
	ptr.resize(nodeinfo.size());
	for (int i = 0; i < nodeinfo.size(); i++)
	{
		struc[i].idx = i + 1;
		struc[i].p = &nodeinfo[i];
		ptr[i] = &struc[i];
	}
	sort(ptr.begin(), ptr.end(), cmp);

	int root = ptr[0]->idx;
	makeTree(-1, 100001, root, 1, nodeinfo);

	vector<vector<int>> answer;
	vector<int> pre;
	preorder(root, &pre);
	vector<int> post;
	postorder(root, &post);
	answer.push_back(pre);
	answer.push_back(post);
	return answer;
}