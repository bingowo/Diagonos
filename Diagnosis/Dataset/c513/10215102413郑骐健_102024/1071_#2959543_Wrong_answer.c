#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define  num 10007

int main()
{
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
        int mid =1;
        for(int i =1;i<=n;i++)
        {
            mid =(mid*(k-i+1))/i;
            mid%=num;
        }
        printf("case #%d:\n",i);
        printf("%d\n",(res1*res2*mid)%num);
    }
    return 0;
}
