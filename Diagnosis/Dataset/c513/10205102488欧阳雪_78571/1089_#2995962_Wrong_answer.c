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


void sassign(int* x,char* s)    //针对字符串的assign操作
{
    int len = strlen(s);
    int i,j;
    if(s[0] == '-') x[0] = 0;
    else x[0] = 1;

    for(i=MAX_LEN-1,j=len-1;i>=1&&isdigit(s[j]);i--,j--)
        x[i] = s[j]-'0';
}
void print(int* x,int N)
{
    int flag = 0;
    INT(temp);
    int j=0;
    if(!x[0])   printf("-");
    for(int i=1;i<MAX_LEN;i++)
    {
        if(!flag && !x[i])  continue;
        flag = 1;
        temp[j++]=x[i];
        //printf("%d",x[i]);
    }

    j--;
    int cnt=0;
    if(j<N)//不足N位 
    {
    	for(int k=0;k<N-j+1;k++)
    	{
    		printf("0");
		}
    	for(int k=0;k<=j;k++)
    	{
    		printf("%d",temp[k]);
		}
	}
	else{
		int t=j+1-N;
		while(t<=j)
		{
			printf("%d",temp[t]);
			t++;
		}
	}
	printf("\n");

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

void multipy(int* x,int* y)//高精度*高精度 
{
    INT(s);
    int temx = x[0];
    s[0] = 1;
    INT(tmp);
    int i=1;
    while(!y[i])    i++;
    for(;i<MAX_LEN;i++)
    {
        mul(s,10);
        cpy(tmp,x);
        mul(tmp,y[i]);
        add(s,tmp);
    }
    cpy(x,s);

    if(temx!=y[0])  x[0] = 0;
    else x[0] = 1;

}

int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int A,B,N;
		scanf("%d%d%d",&A,&B,&N);
		INT(x);
		memset(x,0,sizeof(x));
		assign(x,1);
		/*if(N==0)
		{
			printf("case #%d:\n",i);
			printf("1\n");
			continue;
		}*/

		for(int j=0;j<B;j++)//n个a相乘，高精度*低精度 
		{
			mul(x,A);
		}

		printf("case #%d:\n",i);
		
		print(x,N);
	}
	return 0;
 } 