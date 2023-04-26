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

BIGINT int2BIG(int x)//把int转换成BIGINT 
{
	BIGINT R={0,{0}};
	do
	{
		R.v[R.cnt++]=x%10;
		x/=10;
	 } while(x>0);
	 return R;
}

BIGINT mul(BIGINT S,BIGINT T)//大整数相乘, S.v[i]*T.v[j]->R.v[i+j] ,  R.v[i+j]上大于10进1 
{   
	BIGINT R={S.cnt+T.cnt,{0}};//有效位数至多为S.cnt+T.cnt个    如千百十个4位，十个2位
	int i,j,k,t;
	for(i=0;i<T.cnt;i++)
	{
		int carry=0;
		for(j=0;j<S.cnt;j++)
		{
			t=T.v[i]*S.v[j]+carry+R.v[i+j];//R.V[i+j]的计算值 
			R.v[i+j]=t%10;//有效十进制数 
			carry=t/10;//进位数 
		}
		k=i+j;//此次计算最高位 k
		while(carry>0)//看R.v[k]是否需要进位,算到无法进位为止
		{
			t=R.v[k]+carry;//计算值
			R.v[k]=t%10;
			carry=t/10;
			k++;//下一步算R.v[k+1] 
		} 
	}
	if(R.v[S.cnt+T.cnt-1]==0) R.cnt--;//最高位为0时不计入有效位数 
	return R;
}

BIGINT s2BIG(char*s)
{  int i,l=strlen(s);
	BIGINT R;
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