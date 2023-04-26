#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define  MAXN  200
typedef struct
{
	int cnt;
	int v[MAXN];
}BIG;

void ctB(char*A,BIG*a)//转换 
{
	int l=strlen(A),i=0;
	for(i=l-1;i>=0;i--)
	{  
		a->v[a->cnt++]=A[i]-'0';	
	}
}

int add1(BIG*a,int k)//返回数字变化的最高位 
{	int i=k;
	while(i<=(a->cnt+1))//位数至多cnt+1 
	{    a->v[i]+=1;
		if(a->v[i]<=9) break;
		else a->v[i]=0;
		 i++;
	}
	return i;
}
int main() 
{   int k,T;
	scanf("%d\n",&T);
	for(k=0;k<T;k++)
	{   char A[MAXN]={'\0'};
		scanf("%s",A);
		printf("case #%d:\n",k);
		BIG  a;
		ctB(A,&a);//转换 
		int i=add1(&a,0);//a+1 
		for(i=a.cnt;i>=0;i--)//查看是否是重复数 
		{
			if(a.v[i]==a.v[i+1]) break; 
		}
		
		if(i!=-1)//重复数 
		{	i=add1(&a,i);//在重复数字的最高处的第二位+1，返回发生数字变化的最高位 
			while(i<=a.cnt)//对数字变化最高位前面的可能重复进行循环处理 
			{    if(a.v[i]!=a.v[i+1]) break;//数字变化最高位i与i+1位不同就没有重复 
				i=add1(&a,i);
			}
		}
		i=(a.v[a.cnt+1]==0)?a.cnt:(a.cnt+1);
		for(;i>=0;i--)
			printf("%d",a.v[i]);
		putchar('\n');
	}
	return 0;
}