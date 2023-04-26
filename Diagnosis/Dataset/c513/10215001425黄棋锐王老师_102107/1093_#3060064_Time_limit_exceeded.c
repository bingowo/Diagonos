#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define max 3000 

typedef struct
{
	int cnt;//记录有效位数 
	int v[max];//记录每一位上的数字，v[0]个位，v[1]十位 
}BIGINT;// 表示最大可能位数小于N位的一个大正整数

BIGINT s2BIG(char*s)
{  int i,l=strlen(s);
	BIGINT R={0,{0}};
	for(i=l-1;i>=0;i--)
	{
		R.v[R.cnt++]=s[i]-'0';	
	}
	return R;
}
int flag(BIGINT n)//查看是否有'9' 
{ int i;
	for(i=0;i<n.cnt;i++) 
	{
		if(n.v[i]==9) return i;//有9返回9的位置 
	}
	return -1;
}

int sum(BIGINT n)
{
	int i,co=0;
	for(i=0;i<n.cnt;i++) co+=n.v[i];
	return co;
}

int main() 
{ char s[2000]={'\0'};
	scanf("%s",s);
	BIGINT n;
	n=s2BIG(s);
	int i,t,carry=0,j;
	do
	{
		t=n.v[i]+carry+1;
		n.v[i]=t%10;
		carry=t/10;
		i++;
	 }while(carry>0);
	 if(i>n.cnt) n.cnt=i;
	FLAG:	
	while(flag(n)!=-1)//一直处理到不含9 
	{  	
		i=flag(n);
		for(j=0;j<=i;j++) n.v[j]=0;
		do
	{
		t=n.v[i+1]+carry+1;
		n.v[i+1]=t%10;
		carry=t/10;
		i++;
	 }while(carry>0);
	 if(i>n.cnt) n.cnt=i;
	}
	int cou=sum(n);
	if(cou%9==0) goto FLAG;
	else 
	{   
	for(i=n.cnt-1;i>=0;i--) printf("%d",n.v[i]);
	}
	return 0;
}