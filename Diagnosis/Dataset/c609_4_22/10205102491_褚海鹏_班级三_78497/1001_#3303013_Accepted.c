#include<stdio.h>
int main()
{
	int a,b,c;
	scanf("%d",&a);
	while((scanf("%d %d",&b,&c)!=EOF))
	{
		if(b<0)
		{
			b=-b;
			printf("-");
		}
		char d,s[100]={0};
		int i=0;
		while(b!=0)
		{
			d=b-(b/c)*c+48;
			if(d>57) d=d+7;
			b=b/c;
			s[i]=d;
			i=i+1;
		}
		for(i=i-1;i>=0;i--)printf("%c",s[i]);
		printf("\n");
	}
	return 0;
 }