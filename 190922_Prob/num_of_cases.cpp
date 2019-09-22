#include <iostream>

using namespace std;
const int MAX = 25;
int N, M;
int cony_x, cony_y;
long long int matrix[MAX][MAX];
bool isOut(int x, int y)
{
    if(x<0 ||y<0||x>N ||y>M) 
        return true;
    return false;
}
void init()
{//matrix 셋팅
    for(int i=0; i<MAX; i++)
    {
        matrix[i][0] = 1;
        matrix[0][i] = 1;
    }
    for(int i=1; i<MAX; i++)
    {
        for(int j=1; j<MAX; j++)
        {
            matrix[i][j] = matrix[i-1][j]+matrix[i][j-1];
        }
    }
}
int main(void) {
    scanf("%d %d", &N, &M);
    scanf("%d %d", &cony_x, &cony_y);
    
    if(isOut(cony_x, cony_y))
    {
        printf("fail");
        return 0;
    }
    printf("%d\n", cony_x+cony_y); //최단거리
    
    init();
    printf("%lld", matrix[cony_x][cony_y]);
    return 0;
}