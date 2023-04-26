#include<stdio.h>
int main()
{
    int t;
    scanf("%d\n",&t);
    for(int i=0;i<t;i++)
    {
        long long n=0;
        scanf("%lld\n",&n);
        printf("case #%d:\n",i);
        int fi=n%2,num=1,mod=0,count=1;
        while(n!=0)
        {
            n/=2;
            mod=n%2;
            if(mod!=fi) num+=1;
            if(num>count) count=num;
            fi=mod;
        }
        printf("%d\n",count);
    }
    return 0;
}