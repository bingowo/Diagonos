#include<stdio.h>

long long int f(long long int j)
{
    long long int t,a=0,b=1,c=1;
    
    for(int i = 3;i<j+1;i++)
    {
        t=a+b+c;
        a=b;
        b=c;
        c=t;
    }
    return t;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        long long int j,ans;
        scanf("%lld",&j);
        if(j<2)
            ans = j;
        if(j == 2)
            ans = 1;
        else
            ans = f(j);
        printf("%lld\n",ans);
        
    }
    return 0;
}
