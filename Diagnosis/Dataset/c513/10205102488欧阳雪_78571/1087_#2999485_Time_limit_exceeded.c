#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>
#define MAX_LEN 10000    //定义竖式运算的精度，数值可改变
#define INT(x) int x[MAX_LEN] = {0}     //高精度数的定义方式

void sassign(int* x,char* s)    //针对字符串的assign操作
{
    int len = strlen(s);
    int i,j;
    if(s[0] == '-') x[0] = 0;
    else x[0] = 1;

    for(i=MAX_LEN-1,j=len-1;i>=1&&isdigit(s[j]);i--,j--)
        x[i] = s[j]-'0';
}
void assign(int* x,int y)
{
    if(y>=0)    x[0] = 1;
    else
    {
        x[0] = 0;
        y=-y;
    }
    for(int i=MAX_LEN-1;i>=1&&y;i--)
    {
        x[i] = y%10;
        y/=10;
    }
}
void add(int* x,int*y)//x+1
{
    int r=0;
    for(int i=MAX_LEN-1;i>=1;i--)
    {
        int tmp = x[i]+y[i]+r;
        r = tmp/10;
        x[i] = tmp%10;
    }
}
int lenth(int* x)
{
    int flag = 0,i;
    int cnt=0; 
    for(i=1;i<MAX_LEN;i++)
    {
        if(!flag && !x[i])  continue;
        flag = 1;
        break;
       // printf("%d",x[i]);
    }
    return i;//	起始位置 
}
int Nrept(int*x,int l)//判断是否是非重复数 
{
	int flg=0;
	for(int i=l;i<MAX_LEN;i++)
	{
		if(x[i]==x[i+1])
		{
			flg=1;
			break;
		}
	}
	if(flg==0)return 1;
	else return -1;
}
void print(int* x)
{
    int flag = 0;
    if(!x[0])   printf("-");
    for(int i=1;i<MAX_LEN;i++)
    {
        if(!flag && !x[i])  continue;
        flag = 1;
        printf("%d",x[i]);
    }
    if(!flag)   printf("0");
    printf("\n");
   
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		char s[200]={0};
		scanf("%s",s);
		INT(x);
		INT(y);
		sassign(x,s);
		assign(y,1);
		int l=lenth(x);//起始位置 
		add(x,y);
		while(Nrept(x,l)==-1)
		{
			add(x,y);
			if(Nrept(x,l)==1)break; 
		}
		printf("case #%d:\n",i);
		print(x);
	}
 } 