#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

#define N 1001
#define INF 1000009

typedef long long int lli;

int num[100]={0};

void solve (int a,int b)
{
    scanf("%d%d",&a,&b);
    num[a-1]++;num[b-1]++;
}

int main(void)
{
    int t,n;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int flag = 0;
        scanf("%d",&n);
        for(int j=0;j<n;j++)
        {
            int a,b;
            solve(a,b);
        }
        for(int k = 0;k<100;k++)
        {
            if (num[k]>=2)
            {
                flag = 1;
                break;
            }
        }
        if (flag)
            printf("Poor dxw!");
        else
            printf("Lucky dxw!");
        memset(num,0,sizeof(num));
    }
    return 0;

}
