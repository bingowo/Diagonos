#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int qpow(long long int a,int b,int n)
{
    int N=pow(10,n);
    int ans=1;
    while(b)
    {
        if(b&1) ans=ans*a%N;
        a=a*a%N;
        b>>=1;
    }
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        printf("case #%d:\n",i);
        long long int a;
        int b,n,res,ct=0;
        scanf("%lld %d %d",&a,&b,&n);
        res=qpow(a,b,n);
        int temp=res;
        if(temp!=0)
        {
            while(temp)
            {
                temp=temp/10;
                ct+=1;
            }
        }
        else ct=1;
        if(ct<n)
        {
            for(int j=1;j<=n-ct;j++) printf("0");
        }
        printf("%d\n",res);
    }
    return 0;
}
