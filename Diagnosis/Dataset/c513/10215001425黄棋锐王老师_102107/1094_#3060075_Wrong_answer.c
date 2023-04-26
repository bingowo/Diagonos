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
{ char s[52][200]={'\0'};
	scanf("%s",s);
	BIGINT n;
	n=s2BIG(s);

	return 0;
}