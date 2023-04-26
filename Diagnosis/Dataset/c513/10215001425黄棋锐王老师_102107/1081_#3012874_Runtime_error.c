#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 95
void mul(int*re,int a)
{
	int carry=0,i;
	for(i=0;i<N;i++)
	{	int t=re[i]*a+carry;//进位后的计算值 
		re[i]=t%10;//此位结果值 
		carry=t/10;// 进位数 
	}
}
int main()
{   int k,T;
 scanf("%d",&T);
 for(k=0;k<T;k++)
 {  int re[97]={0};
    int a,n,i;
    scanf("%d %d",&a,&n);
 	printf("case #%d:\n",k);
 	for(i=0;i<n;i++) mul(re,a);
	for(i=97;re[i]==0;i--);
	for(;i>=0;i--) printf("%d",re[i]);
	printf("\n");
 }
	return 0;
}