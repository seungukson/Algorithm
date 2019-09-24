#include <iostream>

using namespace std;

const int MAX = 20010;
int seat[MAX];

int ret_max(int a, int b)
{
    return a>b? a: b;
}
int main(void) {
    int N;
    scanf("%d", &N);
    int first=0;
    int last = 0;
    int width = 0;
    int max_width = 0;
    for(int i=0; i<N; i++)
    {
        scanf("%d", &seat[i]);
    }//자리입력
    
    for(int i=0; i<N; i++)
    {
        if(seat[i]==0) first++;
        else break;
    }// 첫공백
    for(int i=N-1; i>=0; i--)
    {
        if(seat[i]==0) last++;
        else break;
    }//마지막공백
    for(int i=0; i<N; i++)
    {
        if(seat[i]==0) width++;
        if(max_width<width) 
            max_width = width;
        
        if(seat[i]==1) width=0;      
    }//최대공백길이 찾기
    int ans = max(max((max_width+1)/2, first), last);
    printf("%d", ans);
    return 0;
}