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
void BIG2char(BIGINT*A,char*s)
{  int i,j=0;
	for(i=A->cnt-1;i>=0;i--) s[j++]=A->v[i]+'0';
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

BIGINT num(char*s,int x)//x位置上的可能数 
{  int i,l=strlen(s);
	if(x==0)
	{  if(s[0]==s[1]) return int2BIG(1);
		else  return int2BIG(2);
	}
	
	else if(l-1==x)
	{	if(s[x]==s[x-1]) return int2BIG(1);
		else  return int2BIG(2);
	}
	
	else 
	{ if(s[x]==s[x-1]&&s[x]==s[x+1]) return int2BIG(1);
		else if(s[x]==s[x-1]&&s[x]!=s[x+1])return int2BIG(2);
		else if(s[x]!=s[x-1]&&s[x]==s[x+1]) return int2BIG(2);
		else if (s[x]!=s[x-1]&&s[x]!=s[x+1]) return int2BIG(3);
	}
}
int main() 
{ char s[2000]={'\0'};
	scanf("%s",s);
	int i,l=strlen(s);
	BIGINT ANS=int2BIG(1);
	if(l==1) printf("1");
	else 
	{
	for(i=0;i<l;i++)
	{
		ANS=mul(ANS,num(s,i));
	}
	for(i=ANS.cnt-1;i>=0;i--) printf("%d",ANS.v[i]);
	}
	return 0;
}