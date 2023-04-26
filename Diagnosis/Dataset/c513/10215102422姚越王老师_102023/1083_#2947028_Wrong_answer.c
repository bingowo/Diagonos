#include<stdio.h>
#include<stdlib.h>
int main()
{
	int T,i,j,k,N,tmp,cnt;scanf("%d",&T);
	for(int cas=0;cas<T;++cas)
	{
		scanf("%d",&N);
		tmp=1;cnt=0;
		for(i=2;i<=N;++i)
		{
			tmp*=i;
			if(!(tmp%10))while(!(tmp%10))cnt++,tmp/=10;
			else tmp%=10;
		}
		printf("case #%d:\n%d\n",cas,cnt);
	}
	return 0;
}
