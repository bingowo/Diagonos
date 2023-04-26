#include<stdio.h>

long long int f(int n)
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
        ans = f(m)/(f(n)*f(m-n));
        printf("%d\n",ans);
        
    }
    return 0;
}
