#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>
#define MAX_LEN 501    //定义竖式运算的精度，数值可改变
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
void assign(int* x,int y)//数字->数组，可以用于赋值assign(x,1);
{

    for(int i=MAX_LEN-1;i>=1&&y;i--)
    {
        x[i] = y%10;
        y/=10;
    }
}
void print(int* x)
{
    int flag = 0;
    for(int i=1;i<MAX_LEN;i++)
    {
        if(!flag && !x[i])  continue;  //去除前导0
        flag = 1;
        printf("%d",x[i]);
    }
    if(!flag)   printf("0");
    printf("\n");
}
int main()
{
	int k,n;
	scanf("%d%d",&k,&n);
	int a[MAX_LEN][MAX_LEN]={0};
	memset(a,0,sizeof(0));
	assign(a[0],0);
	assign(a[1],1);
	for(int i=2;i<n;i++)
	{
		if(k>=i+1)
		{
			for(int t=0;t<i;t++)
			{
				add(a[i],a[t]);
				//print(a[i]);
			//	a[i]+=a[t];
			}
		}
		else{
			int j=i-1;
			for(int m=0;m<k;m++)
			{
				add(a[i],a[j]);
				//a[i]+=a[j];
				j--;
			}
		}
	}
//	printf("%lld",a[n-1]);
    print(a[n-1]);
 } 