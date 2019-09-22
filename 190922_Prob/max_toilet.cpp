#include <iostream>

using namespace std;
const int MAX = 1001;
int N;
int toilet[MAX];
int tim[MAX][2];
int max_idx = -1;

void toilet_out(int t)
{
    for(int i=0; i<N; i++)
    {
        if(toilet[i]==t) toilet[i] =0;
    }
}
void toilet_in(int t)
{
    int idx=0;
    for(int i=0; i<N; i++)
    {
        int start = tim[i][0];
        int end = tim[i][1];
        if(start != t)
            continue; //들어갈애 아니면 제낀다
        
        while(toilet[idx]!=0) idx++;
        toilet[idx] = end;
    }
    if(max_idx<idx) max_idx = idx;
}
int main(void) {
    scanf("%d", &N);
    
    for(int i=0; i<N; i++)
    {
        scanf("%d %d", &tim[i][0], & tim[i][1]);//start, end
    }
    for(int t=0; t<151; t++)
    {
        toilet_out(t); // 화장실에서 뺴기
        toilet_in(t); // 화장실에서 넣기

    }
    max_idx++;
    printf("%d",max_idx);
    return 0;
}