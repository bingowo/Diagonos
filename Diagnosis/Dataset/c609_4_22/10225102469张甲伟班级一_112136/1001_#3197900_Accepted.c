#include<stdio.h>
int N,T,R,t;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		int answer[1000];
		int i=0;
		scanf("%d%d",&N,&R);
		if(N<0)
		{
			printf("-");
			N=(-1)*N;
		}
		while(N)
		{
			t=N%R;
			N/=R;
			answer[i]=t;
			/*if(t>=10)
				answer[i]='A'+(t-10);
			else
				answer[i]=(t-'0');*/
			i++;		
		}
		for(int j=i-1;j>=0;j--)
		{
			if(answer[j]>=10)
				printf("%c",answer[j]-10+'A');
			else
				printf("%d",answer[j]);
		}
		printf("\n");
	}
	return 0;
 } 