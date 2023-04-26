#include<stdio.h>

long long int f(int m,int n)
{
    if(n==0)
        return 1;
    else
    {
        long long int ans=1;
    	for(int i=n+1;i<m+1;i++)
    	{
        	ans = ans*i;
    	}
    	return ans;
    }
    
}

long long int func(int n)
{
    if(n==0)
        return 1;
    else
    {
        long long int ans=1;
    	for(int i=1;i<n+1;i++)
    	{
        	ans = ans*i;
    	}
    	return ans;
    }
    
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
        if(n==0)
            ans = 1;
        else
            ans = f(m,n)/func(m-n);
        printf("%lld\n",ans);
        
    }
    return 0;
}
