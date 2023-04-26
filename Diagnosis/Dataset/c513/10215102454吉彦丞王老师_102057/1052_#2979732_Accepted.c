#include<stdio.h>
#include<math.h>
#include<stdlib.h> 
#include<string.h>
int main()
{
	int t,i=0,b[128];
	char a[21];
	
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		b['O']=0,b['W']=0,b['U']=0,b['H']=0,b['G']=0,b['F']=0,b['X']=0,b['S']=0,b['I']=0,b['Z']=0; 
		scanf("%s",a);
		int j=0;
		while(a[j]!='\0')
		{
			b[a[j]]++;j++;
		}
		printf("case #%d:\n",i);
		for(int k=0;k<b['Z'];k++)
		{
			printf("0");
		}
		for(int k=0;k<(b['O']-b['W']-b['U']-b['Z']);k++)
		{
			printf("1");
		}
		for(int k=0;k<b['W'];k++)
		{
			printf("2");
		}
		for(int k=0;k<(b['H']-b['G']);k++)
		{
			printf("3");
		}
		for(int k=0;k<b['U'];k++)
		{
			printf("4");
		}
		for(int k=0;k<b['F']-b['U'];k++)
		{
			printf("5");
		}
		for(int k=0;k<b['X'];k++)
		{
			printf("6");
		}
		for(int k=0;k<b['S']-b['X'];k++)
		{
			printf("7");
		}
		for(int k=0;k<b['G'];k++)
		{
			printf("8");
		}
		for(int k=0;k<b['I']-b['F']+b['U']-b['X']-b['G'];k++)
		{
			printf("9");
		}		
		printf("\n");	
	}	
	return 0;
}