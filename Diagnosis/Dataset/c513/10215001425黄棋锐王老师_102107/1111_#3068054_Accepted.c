#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define max 1000

typedef struct
{
	int c0,c1,c2,c3;
}FUN;


int fun(FUN fx,int x)
{
	int y=0;
	y=fx.c0+fx.c1*x+fx.c2*x*x+fx.c3*x*x*x;
	return y;
}

int main() 
{ 	char s[100]={'\0'};
	while(scanf("%s",s)!=EOF)
{	char graph[41][41];
	int i=0,j=0,l=strlen(s);
	
//	for(i=0;i<41;i++)
//		for(j=0;j<41;j++)
//		 graph[i][j]='.';
		memset(graph,'.',41*41);
	graph[0][20]='^';
	for(j=20,i=1;i<41;i++) graph[i][j]='|';
	for(i=20,j=0;j<40;j++) graph[i][j]='-';
	graph[20][20]='+';
	graph[20][40]='>';
	//*****************初始化坐标系 
	
	
	FUN fx={0,0,0,0};
	i=5;
	do
 { 	char xi[100]={'\0'};
 	int sign=1;//记录符号
 	
 	if(s[i]=='+') sign=1,i++;
 	else if(s[i]=='-') sign=-1,i++;//处理符号，可有可无，'+','-',或无符号 
 	
 	
 	for(j=0;i<l&&'0'<=s[i]&&s[i]<='9';i++) xi[j++]=s[i];//记录数值 
	int val=1;
	if(strlen(xi)>0) val=atoi(xi);
	
 	if(s[i]=='x')
	 {	
	 	if(i+1<l&&s[i+1]=='^')
	 	{	i=i+2;
	 		if(s[i]=='3') fx.c3=val*sign;
	 		else if(s[i]=='2') fx.c2=val*sign;
		 }
		 
	 	else fx.c1=val*sign;
	 	i++;
	 }
	 
 	else fx.c0=val*sign;//常数项 
	  
 }while(i<l);
    //*********************读入f(x) 
	
	
	int x=-20,y=0;
	while(x<=20)
	{	y=fun(fx,x);
		if(abs(y)<=20)
		{
		int xi=abs(x+20),yi=abs(y-20);
		graph[yi][xi]='*';
		}
		x++;
	}
	
	for(i=0;i<41;i++)
		for(j=0;j<41;j++)
		 {
		 	printf("%c",graph[i][j]);
		 	if(j==40) putchar('\n');
		 }
	putchar('\n');
	memset(s,'\0',100);
}
    return 0;
}