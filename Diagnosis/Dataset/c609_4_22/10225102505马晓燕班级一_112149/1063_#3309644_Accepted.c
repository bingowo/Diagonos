#include <stdio.h>
#define N 50

int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int n;
		scanf("%d",&n);
		
        long long p[N+1]={0};
        p[1]=1,p[2]=2,p[3]=4,p[4]=8;
        for(int i=5;i<=n;i++)
            p[i]=p[i-1]+p[i-2]+p[i-3]+p[i-4];
        printf("case #%d:\n",i);
		printf("%lld\n",p[n]);

	}
}