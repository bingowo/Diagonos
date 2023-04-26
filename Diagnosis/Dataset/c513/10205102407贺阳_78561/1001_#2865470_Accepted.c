#include<stdio.h>
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int N,R,a,b,c=0;
		scanf("%d %d",&N,&R);
		if(N<0)
		{
			a=-N;
		}
		else
		{
			a=N;
		}
		char s[32];
		for(int j=0;j<32;j++)
		{
			b=a%R;
			if(b<10)
			{
				s[j]=b + '0';
			}
			else
			{
				s[j]='A'+b-10;
			}
			c++;
			a=a/R;
			if(a==0)
			{
				break;
			}
		}
		//for(int t=0;t)
		if(N<0)
		{
			printf("-");
		}
		for(int m=0;m<c;m++)
		{
			printf("%c",s[c - m - 1]);
		}
		printf("\n");
	}
}