#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const int ABO[4][4][4]={{{1,0,0,1},{1,1,1,0},{1,1,1,1},{1,0,0,1}},{{1,1,1,0},{1,1,1,0},{1,1,1,0},{1,0,1,0}},{{1,1,1,1},{1,1,1,0},{0,0,1,1},{0,0,1,1}},{{1,0,0,1},{1,0,1,0},{0,0,1,1},{0,0,0,1}}};
int read()
{
	int x=0;
	char s[4];
	scanf("%s",s);
	if(!strcmp(s,"A")){x=1;}
	else if(!strcmp(s,"B")){x=3;}
	else if(!strcmp(s,"AB")){x=2;}
	else if(!strcmp(s,"O")){x=4;}
	else {x=0;}
	return x;
}
void print(int a)
{
	if(a==1) printf("A");
	else if(a==2) printf("AB");
	else if(a==3) printf("B");
	else printf("O");
}
void write(int ans[])
{
	int b=0;
	for(int i=0;i<4;i++)
	{
		b+=ans[i];
	}
	if(b==0) printf("impossible");
	else
	{
		int c=0;
		printf("{");
		for(int i=0;i<4;i++)
		{
			if(ans[i])
			{
				if(c!=0) printf(",");
				print(i+1);c++;
			}
		}
		printf("}");
	}
}
int main()
{
	int a,b,c,ans[4]={0};
	a=read();
	b=read();
	c=read();
	if(a==0)
	{
		for(int i=0;i<4;i++) ans[i]=ABO[i][b-1][c-1];
	}
	if(b==0)
	{
		for(int i=0;i<4;i++) ans[i]=ABO[a-1][i][c-1];
	}
	if(c==0)
	{
		for(int i=0;i<4;i++) ans[i]=ABO[a-1][b-1][i];
	}
	if(a!=0) print(a);
	else write(ans);
	printf(" ");
	if(b!=0) print(b);
	else write(ans);
	printf(" ");
	if(c!=0) print(c);
	else write(ans);
	printf("\n");
}
