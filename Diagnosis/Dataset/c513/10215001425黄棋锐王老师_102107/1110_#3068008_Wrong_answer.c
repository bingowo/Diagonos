#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define max 1000

typedef struct
{	int sign;//符号 
	int cnt;//记录有效位数 
	int v[max];//记录每一位上的数字，v[0]个位，v[1]十位 
	char goal;//未知数 
}BIGINT;// 表示最大可能位数小于N位的一个大正整数


BIGINT s2BIG(char*s)
{  int i,l=strlen(s);
	BIGINT R={1,0,{0}};
	for(i=l-1;i>=0;i--)
	{
		R.v[R.cnt++]=s[i]-'0';	
	}
	return R;
}




int main() 
{ 	char s[100]={'\0'};
	scanf("%s",s);
	int p=0;//记录数值 
	int cx=0;//记录未知数系数
	int flag=1;//判断系数在等号左边还是右边
	int fl=-1; //判断数值在等号左边还是右边
	char goal;
	int i=0,l=strlen(s),j=0,k=0,temp=0,pn=0,q=0; 
do
 { 	char xi[100]={'\0'};
 	int sign=1;//记录符号
 	
 	if(s[i]=='+') sign=1,i++;
 	else if(s[i]=='-') sign=-1,i++;//处理符号，可有可无，'+','-',或无符号 
 	
 	
 	j=0;
 	for(;i<l&&'0'<=s[i]&&s[i]<='9';i++) xi[j++]=s[i];//记录数值 
	int val=1;
	if(strlen(xi)>0) val=atoi(xi);
	
 	if('a'<=s[i]&&s[i]<='z') goal=s[i++],cx+=val*sign*flag;//未知数系数
 	else p+=val*sign*fl;
	
 	if(s[i]=='=') i++,flag=-1,fl=1;
 	
 	
 }while(i<l);
 
	double x=(double)p/(double)cx;
	printf("%c=%lf",goal,x);
	
    return 0;
}