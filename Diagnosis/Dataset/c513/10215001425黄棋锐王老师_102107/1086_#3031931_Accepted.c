#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define  L 500//划分整数与小数部分 
void Input(int*a,char*s)
{
	int i=0,j=0,k;
	while(s[i]&&s[i]!='.') i++;//找小数点，没有就到底strlen（s） 
	for(j=i-1,k=L;j>=0;j--,k--)//整数部分,从K=L开始往前记录，前面留一位来进位 
		a[k]=s[j]-'0';
	for(j=i+1,k=L+1;j<strlen(s);j++,k++)//小数部分 
		a[k]=s[j]-'0';
}
void Sub(int*a,int*b,int N)//计算大数减小数 
{
	int i,carry=0;
	for(i=2*L;i>=L+N+1;i--)//小数点N位后面 
	{	a[i]-=carry;
		if(a[i]>=b[i])
		{	carry=0;
			a[i]-=b[i];
		 } 
		else
	 		{   carry=1;
	 			a[i]=a[i]+10-b[i];
			}
	}
	if(a[L+N+1]>=5) a[L+N]+=1;//四舍五入 
	
	for(;i>=0;i--)//小数点N位前面 
	{	a[i]-=carry;
		if(a[i]>=b[i])
		{	carry=0;
			a[i]-=b[i];
		 } 
		else
	 		{   carry=1;
	 			a[i]=a[i]+10-b[i];
			}
	}
}

int main() 
{   int A[1002]={0},B[1002]={0},i;
	char sa[1002]={'\0'},sb[1002]={'0'};
	int N;
	scanf("%s %s %d",sa,sb,&N);
	Input(A,sa);
	Input(B,sb);
	for(i=0;i<=2*L;i++) sa[i]=A[i]+'0',sb[i]=B[i]+'0';//重新处理字符串用于比较 
	if(strcmp(sa,sb)>0) //A>=B
	{ Sub(A,B,N);
	for(i=0;i<=L&&A[i]==0;i++);//前置0去掉
	if(i==L+1) printf("0");
	else
	{
		for(;i<=L;i++) printf("%d",A[i]);
	}
	putchar('.');//以上为整数部分 
	for(i=L+1;i<=L+N;i++)
		printf("%d",A[i]);
	} 
	else 
	{	Sub(B,A,N);
		putchar('-');
		for(i=0;i<=L&&B[i]==0;i++);//前置0去掉
	if(i==L+1) printf("0");
	else
	{
		for(;i<=L;i++) printf("%d",B[i]);
	}
	putchar('.');//以上为整数部分 
	for(i=L+1;i<=L+N;i++)
		printf("%d",B[i]);
	}
	return 0;
}