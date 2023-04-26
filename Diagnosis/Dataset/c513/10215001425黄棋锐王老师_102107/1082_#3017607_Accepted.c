#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define  L 500
void Input(int*a,char*s)
{
	int i=0,j=0,k;
	while(s[i]&&s[i]!='.') i++;//找小数点，没有就到底strlen（s） 
	for(j=i-1,k=L;j>=0;j--,k--)//整数部分,从K=L开始记录，前面留一位来进位 
		a[k]=s[j]-'0';
	for(j=i+1,k=L+1;j<strlen(s);j++,k++)//小数部分 
		a[k]=s[j]-'0';
}
void Add(int*a,int*b,int N)
{
	int i;
	for(i=2*L;i>L+N;i--)//小数点N位以后 
	{   
	   a[i]+=b[i]; 
	   a[i-1]+=a[i]/10;
	   a[i]%=10;  
	}
	if(a[i+1]>=5) a[i]+=1;//四舍五入 
	
	for(;i>0;i--)
	{
		a[i]+=b[i];
		a[i-1]+=a[i]/10;
		a[i]%=10;
	}
}
void Output(int*A,int N)
{	int i;
	for(i=0;i<=L&&A[i]==0;i++);//前置0去掉
	if(i==L+1) printf("0");
	else
	{
		for(;i<=L;i++) printf("%d",A[i]);
	}
	putchar('.');//整数部分 
	for(i=L+1;i<=L+N;i++)
		printf("%d",A[i]);
}
int main() 
{   int A[1002]={0},B[1002]={0},i;
	char sa[502]={'\0'},sb[502]={'0'};
	int N;
	scanf("%s %s %d",sa,sb,&N);
	Input(A,sa);
	Input(B,sb);
	Add(A,B,N);
	Output(A,N);
	return 0;
}