#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>
#define MAX_LEN 5000    //定义竖式运算的精度，数值可改变
#define INT(x) int x[MAX_LEN] = {0}     //高精度数的定义方式

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
    //return 0;
}
int IsEmpty(int* x)
{
    for(int i=1;i<MAX_LEN;i++)
    {
        if(x[i])    return 0;
    }
    return 1;
}
void add(int* x,int* y)
{
    int r=0;
    for(int i=MAX_LEN-1;i>=1;i--)
    {
        int tmp = x[i]+y[i]+r;
        r = tmp/10;
        x[i] = tmp%10;
    }
}
void cpy(int* x,int* y)
{
    for(int i=0;i<MAX_LEN;i++)
            x[i] = y[i];
}


void mul(int* x,int y)//高精度乘以低精度 
{
    int r=0;
    if((!x[0]&&y<=0) || (x[0]&&y<0))
    {
        x[0]=!x[0];
        y=-y;
    }
    for(int i=MAX_LEN-1;i>=1;i--)
    {
        int tmp = x[i]*y +r;
        r = tmp/10;
        x[i] = tmp%10;
    }
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int N;
		scanf("%d",&N);
		if(N==1){//0？？？？ 
		    printf("case #%d:\n",i);
			printf("0\n");
		}
		else{
			INT(ANS);
			memset(ANS,0,sizeof(ANS));
			assign(ANS,1);
			for(int j=2;j<=N;j++)
			{
				mul(ANS,j);
			}
			int cnt=0;
		    int k=MAX_LEN-1;
		    while(ANS[k]==0)
		    {
		    	cnt++;
			}
			printf("case #%d:\n",i);
			printf("%d\n",cnt);
		}
	}
	return 0;
}