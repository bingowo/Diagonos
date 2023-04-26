#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>


#define INF 1000009

typedef long long int lli;

int num[100]={0};int N=0;

void solve (int a,int b)
{
    scanf("%d%d",&a,&b);
    if(num[a-1]==0) N++;
    if(num[b-1]==0) N++;
    num[a-1]++;num[b-1]++;

}

int main(void)
{
    int t,n;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int flag = 0;
        N=0;
        scanf("%d",&n);
        for(int j=0;j<n;j++)
        {
            int a,b;
            solve(a,b);
        }
        for(int k = 0;k<100;k++)
        {
            if (num[k]>=2&&N!=1)
            {
                flag = 1;
                break;
            }
        }
        if (flag)
            printf("Poor dxw!\n");
        else
            printf("Lucky dxw!\n");
        memset(num,0,sizeof(num));
    }
    return 0;

}
