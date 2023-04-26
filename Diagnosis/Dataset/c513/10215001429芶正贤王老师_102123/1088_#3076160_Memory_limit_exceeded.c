#include<stdio.h>

long long int f(int m,int n)
{
    if(n==0 && m==n)
        return 1;
    else
        return f(m-1,n-1)+f(m-1,n);
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        int m,n;
        scanf("%d %d",&m,&n);
        long long int ans;
        ans = f(m,n);
        printf("%lld\n",ans);
        
    }
    return 0;
}
