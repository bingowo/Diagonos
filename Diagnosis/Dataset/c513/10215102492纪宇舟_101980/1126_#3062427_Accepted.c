#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
typedef struct
{
	int sig,cnt;
	int num[105];
}BIGNUM;
void print(BIGNUM A)
{
	if(A.sig==-1)printf("-");if(A.cnt==0)printf("0");
	for(int i=A.cnt;i>=1;i--)printf("%d",A.num[i]);
}
BIGNUM Trans(long long x)
{
	BIGNUM X;X.sig=1;X.cnt=0;X.num[1]=0;
	if(x<0){x=-x;X.sig=-1;}
	while(x)
	{
		X.num[++X.cnt]=x%10;
		x/=10;
	}
	if(X.cnt==0)X.cnt=1;
	return X;
} 
int CMP(BIGNUM A,BIGNUM B)
{
	if(A.cnt>B.cnt)return  1;
	if(A.cnt<B.cnt)return -1;
	for(int i=A.cnt;i>=1;i--)
	if(A.num[i]<B.num[i])return -1;
	else if(A.num[i]>B.num[i])return 1;
	return 0;
}
BIGNUM Add(BIGNUM A,BIGNUM B);
BIGNUM Minus(BIGNUM A,BIGNUM B)
{
	if(A.sig==-1&&B.sig==-1)
	{
		A.sig=B.sig=1;
		return Minus(B,A);
	}
	if(A.sig==1&&B.sig==-1)
	{
		B.sig=1;
		return Add(A,B);
	}
	if(A.sig==-1&&B.sig==1)
	{
		BIGNUM X;A.sig=1;
		X=Add(A,B);X.sig=-1;
		return X;
	}
	BIGNUM X;
	if(CMP(A,B)==-1)
	{X=A;A=B;B=X;A.sig=-1;}
	for(int i=1;i<=A.cnt;i++)
	{
		if(i>B.cnt)B.num[i]=0;
		A.num[i]-=B.num[i];
		if(A.num[i]<0)
		{
			A.num[i]+=10;A.num[i+1]-=1;
		}
	}
	int CNT=1;
	for(int i=A.cnt;i>=1;i--)
	if(A.num[i]!=0){CNT=i;break;}
	A.cnt=CNT;return A;
}
int MAX(int x,int y)
{
	if(x>y)return x;
	return y;
}
BIGNUM Add(BIGNUM A,BIGNUM B)
{
	if(A.sig>0&&B.sig<0)
	{
		B.sig=1;return Minus(A,B);
	}
	if(A.sig<0&&B.sig>0)
	{
		A.sig=1;return Minus(B,A);
	}
	if(A.sig<0&&B.sig<0)A.sig=-1;
	int n=MAX(A.cnt,B.cnt);
	for(int i=1;i<=n;i++)
	{
		if(i>B.cnt)B.num[i]=0;
		A.num[i]+=B.num[i];
		if(i+1>A.cnt)A.num[i+1]=0;
		if(A.num[i]>=10)
		{
			A.num[i]-=10;A.num[i+1]+=1;
		}
	}
	int CNT=1;
	for(int i=n+1;i>=1;i--)
	if(A.num[i]!=0){CNT=i;break;}
	A.cnt=CNT;return A;
}
int main()
{
	long long minm=0,sum=0,qsum=0,x;
	BIGNUM ans=Trans(sum);//题为异或
	int n;scanf("%d",&n);
	while(n--)
	{
		scanf("%lld",&x);
		qsum^=x;ans=Add(ans,Trans(x));
		if(minm==0||x<minm)minm=x;
	}
	if(qsum!=0)printf("-1");
	else print(Minus(ans,Trans(minm)));
	return 0;
}