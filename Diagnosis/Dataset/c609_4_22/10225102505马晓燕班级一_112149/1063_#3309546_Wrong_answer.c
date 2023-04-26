#include <stdio.h>
#define N 50

long long f(int n,int p[])
{
	if(n<0)
        return 0;
    else if(n==0)
        return 1;
    else if(p[n] >0)
        return p[n];
	else
        p[n] = f(n-1,p) + f(n-2,p) + f(n-3,p) + f(n-4,p);
    return p[n];
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int n;
		scanf("%d",&n);
        long long p[N+1]={0};
        //p[1]=1,p[2]=2,p[3]=4,p[4]=8;
		printf("%lld\n",f(n,p));

	}
}