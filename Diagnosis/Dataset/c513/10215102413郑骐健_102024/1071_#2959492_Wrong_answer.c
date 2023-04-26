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
        int a,b,n,m,k;
        scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
        int a_=a%num;
        int b_=b%num;
        int res1 = 1;
        int res2 = 1;
        for(int z =0;z<n;z++)
        {
            res1*=a_;
            if(res1>=num)res1%=num;
        }
         for(int z =0;z<m;z++)
        {
            res2*=b_;
            if(res2>=num)res2%=num;
        }
        int mid =1;
        for(int i =1;i<=n;i++)
        {
            mid =(mid*(k-i+1))/i;
            if(mid >=num)mid%=num;
        }
        res1*=mid;
        res1%=num;
        printf("case #%d:\n",i);
        printf("%d\n",(res1*res2)%num);
    }
    return 0;
}
