#include<stdio.h>
#include<stdlib.h>
#include<string.h>

long long num[16][2]={{0,0},{1,0},{-1,1},{0,1},
			{0,-2},{1,-2},{-1,-1},{0,-1},
			{2,2},{3,2},{1,3},{2,3},
			{2,0},{3,0},{1,1},{2,1}
			};
			
int main()
{
	char s[100];scanf("%s",s);
	long long r=0,i=0,sign='+';
	for(int index=2;s[index]!=0;index++)
	{
		int n=s[index]>='0' && s[index]<='9'?s[index]-'0':s[index]-'A'+10;
		r=r*(-4)+num[n][0];
		i=i*(-4)+num[n][1];
	}
	if(i==0 && r==0)
		printf("0");
	else if(i==0)
		printf("%d",r);
	else
	{
		if(r!=0 && i>0)printf("%d+",r);
		else if(r!=0) printf("%d",r);
		if(i!=1 && i!=-1)
			printf("%di",i);
		else if(i==1)
			printf("i"); 
		else if(i==-1)
			printf("-i");
	}
	return 0;
}