#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>
const int ABO[4][4][4]=
{1,0,0,1,1,1,1,0,1,1,1,1,1,0,0,1,
1,1,1,0,1,1,1,0,1,1,1,0,1,0,1,0,
1,1,1,1,1,1,1,0,0,0,1,1,0,0,1,1,
1,0,0,1,1,0,1,0,0,0,1,1,0,0,0,1};
int read()
{
	char s[10];
	scanf("%s",s);
	int flag=0;
	if(!strcmp(s,"A")) flag=1;
	else if(!strcmp(s,"B")) flag=3;
	else if(!strcmp(s,"AB")) flag=2;
	else if(!strcmp(s,"O")) flag=4;
	else if(!strcmp(s,"?")) flag=0;
	return flag;
}
void print(int x,int type)
{
	if(type==1) printf("{");
	else if(type>1) printf(",");
	if(x==1) printf("A");
	else if(x==2) printf("AB");
	else if(x==3) printf("B");
	else if(x==4) printf("O");
}
void write()
{
	int ans_ABO[4];
	int ABO=0;
	for(int i=0;i<4;i++) ABO+=ans_ABO[i];
	if(ABO==0) printf("impossible");
	else
	{
		int cnt=0;
		for(int i=0;i<4;i++)
			if(ans_ABO[i])
			{
				cnt++;
				print(i+1,cnt);
			}
		printf("}");
	}
}

int main()
{
	int ans_ABO[4];
	int fa,mo,ch;
	fa=read();mo=read();ch=read();
	if(fa==0)
	{
		int m1,c1;
		m1=mo-1;
		c1=ch-1;
		for(int i=0;i<4;i++)
			ans_ABO[i]=ABO[i][m1][c1];
	}
	if(mo==0)
	{
		int f1,c1;
		f1=fa-1;
		c1=ch-1;
		for(int i=0;i<4;i++)
			ans_ABO[i]=ABO[f1][i][c1];
	}
	if(ch==0)
	{
		int m1,f1;
		m1=mo-1;
		f1=fa-1;
		for(int i=0;i<4;i++)
			ans_ABO[i]=ABO[f1][m1][i];
	}
	if(fa!=0) print(fa,0);
	else write();
	printf(" ");
	if(mo!=0) print(mo,0);
	else write();
	if(ch!=0) print(ch,0); 
	else write();
	printf("\n");
	return 0;
}