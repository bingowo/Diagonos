#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int N,R;
		scanf("%d%d",&N,&R);
		int sign=1;
		if(N<0) sign=-1,N=-N;
		int s[100]={0};
		char ans[100];
		int t=0;
		while(N>0)
		{
			s[t++]=N%R;
			N/=R;
		}
		for(int j=0;j<t;j++)
		{
			if(s[j]>=10) ans[j]=s[j]-10+'A';
			else ans[j]=s[j]+'0';
		}
		if(sign=-1) printf("-");
		for(int j=t-1;j>=0;j--) printf("%c",ans[j]); 
		printf("\n");
	}
	return 0;
} 