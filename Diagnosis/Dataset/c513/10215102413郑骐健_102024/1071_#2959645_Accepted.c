#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define  num 10007

int main()
{
    int(*p1)[1001] = (int(*)[])malloc(sizeof(int)*1001*1001);
    for(int i =0;i<1001;i++)
    {
        p1[0][i] = 1;
        p1[i][0] = 1;
    }
    for(int g =1;g<1001;g++)
    {
        for(int k = 1;k<1001;k++)
        {
            p1[g][k] = (p1[g-1][k] + p1[g][k-1])%num;
        }
    }
    int t;
    scanf("%d",&t);
    for(int i =0;i<t;i++)
    {
        long long a,b,n,m,k;
        scanf("%lld%lld%lld%lld%lld",&a,&b,&k,&n,&m);
        int a_=a%num;
        int b_=b%num;
        int res1 = 1;
        int res2 = 1;
        for(int z =0;z<n;z++)
        {
            res1*=a_;
            res1%=num;
        }
         for(int r =0;r<m;r++)
        {
            res2*=b_;
            res2%=num;
        }

        res1 = (res1*res2)%num;


        printf("case #%d:\n",i);

        printf("%d\n",(res1*p1[n][m])%num);
    }
    return 0;
}
