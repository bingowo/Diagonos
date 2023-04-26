#include <stdio.h>

long long ans[51]={0};

long long int solve(int n)
{
    if(n<0) return 0;
    else if(n==1||n==0) return 1;
    else {if(!ans[n])
    {
        ans[n]=solve(n-1)+solve(n-2)+solve(n-3)+solve(n-4);
        return ans[n];
    }
    else return ans[n];
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        printf("case #%d:\n",i);
        printf("%lld\n",solve(n));

    }
    return 0;
}
