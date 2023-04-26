#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>
#define MAX_LEN 501    //定义竖式运算的精度，数值可改变
#define INT(x) int x[MAX_LEN] = {0}     //高精度数的定义方式
//方法是：先对齐小数点，标记小数点，再运算 
int main()
{
	INT(x);
	INT(y);
	
	char s1[1000],s2[1000];
	int m1,m2,mmax,remain;
	
	scanf("%s%s",s1,s2);
	scanf("%d",&remain);
	
	for(m1=0;m1<strlen(s1)&&s1[m1]!='.';m1++);//m1,m2记录小数点位置 
	for(m2=0;m2<strlen(s2)&&s2[m2]!='.';m2++);
	
	if(m1>m2){
		mmax=m1;
	}
	else{
		mmax=m2;
	}
	
	//对齐之整数部分 i1表示s1整数末尾在x[]中的位置,从后往前存 
	for(int i1=mmax+2,j1=m1-1;j1>=0;i1--,j1--)x[i1]=s1[j1]-'0'; 
	for(int i2=mmax+2,j2=m2-1;j2>=0;i2--,j2--)y[i2]=s2[j2]-'0';
	
	x[mmax+3]=999;//标记小数点为999 
	y[mmax+3]=999;
	
	//对齐之小数部分 i3表示s1小数开头在x[]中的位置，从前往后存 
	for(int i3=mmax+4,j3=m1+1;j3<strlen(s1);i3++,j3++)x[i3]=s1[j3]-'0';
	for(int i4=mmax+4,j4=m2+1;j4<strlen(s2);i4++,j4++)x[i4]=s2[j4]-'0';
	
	int mm,tem;
	for(int k=MAX_LEN-1;k>=0;k--)//加法运算 
	{
		if(x[k-1]==999)mm=2;//标记整数小数相加分界线 
		else mm=1;
		
		if(x[k]!=999)
		{
			x[k]=x[k]+y[k];
			if(x[k]>=10)//有进位
			{
				tem=x[k]/10;
				x[k]%=10;
				x[k-mm]+=tem;
			 }
			  
		}
	}
	
	//四舍五入（要考虑入了进位的情况） 
	int t=mmax+3+remain; //不管整数部分有多少位，对齐后从mmax到小数部分走3位
	if(x[t+1]>=5)
	{
		x[t]++;
		for(;t>0;t--)//判断有无进位
		{
			if(x[t-1]==999)mm=2;
			else mm=1;
			if(x[t]>=10&&x[t]!=999)
			{
				tem=x[t]/10;
				x[t]%=10;
				x[t-mm]+=tem;
			}
			
		 } 
	}
	
	int f=0;
	for(int z=0;x[z]==0;z++)f++;//不输出前导0 
	if(x[f]!=999)//输出整数部分 
	{
		for(;x[f]!=999;f++)
		{
			printf("%d",x[f]);
		}
	}
	else{
		printf("0");
	}
	printf(".");
	f++;
	
	int g;
	for(g=0;g<remain;g++,f++)//输出小数部分 
	{
		printf("%d",x[f]);
	}
	
	return 0;
}
