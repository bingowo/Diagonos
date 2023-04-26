#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	char opt[250];
	int x,T;
	int N,R,cnt;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&R);
		if(N<0){printf("-");N=-N;}
		else if(N==0){printf("0\n");continue;}
		cnt=0;
		while(N)
		{
			x=N%R;N/=R;
			if(x>10)opt[++cnt]='A'+x-10;
			else opt[++cnt]=x+'0';
		}
		while(cnt)printf("%c",opt[cnt--]);
		printf("\n");
	}
	return 0;
}