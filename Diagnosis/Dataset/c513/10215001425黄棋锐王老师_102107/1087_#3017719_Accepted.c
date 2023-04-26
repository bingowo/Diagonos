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
	while(i<=a->cnt)//位数至多cnt+1 
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
		int i=0;
		BIG  a;//BIGINT也要手工初始化
		a.cnt=0;
		for(i=199;i>=0;i--) a.v[i]=0;
		ctB(A,&a);//转换 
		i=add1(&a,0);//a+1 
		for(i=a.cnt-1;i>=0;i--)//查看是否是重复数 
		{
			if(a.v[i]==a.v[i+1]) break; 
		}
		
		if(i!=-1)//重复数 
		{	i=add1(&a,i);//在重复数字的最高处的第二位+1，返回发生数字变化的最高位 
			while(i<a.cnt)//对数字变化最高位前面的可能重复进行循环处理 ,至多到a的最高位 
			{    if(a.v[i]!=a.v[i+1]) break;//数字变化最高位i与i+1位不同就没有重复 
				i=add1(&a,i);
			}
			int j;
			for(j=i-1;j>=0;j--)//交替添加0和1，保证最小 
			{
				a.v[j]=0+(i-j+1)%2;
			}
		}
		i=(a.v[a.cnt]==0)?a.cnt-1:a.cnt;
		for(;i>=0;i--)
			printf("%d",a.v[i]);
		printf("\n");
	}
	return 0;
}