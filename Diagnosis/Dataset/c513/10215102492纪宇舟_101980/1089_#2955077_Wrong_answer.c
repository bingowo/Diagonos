#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
	int sig,cnt;
	int num[105];
}BIGNUM;
int N;
void print(BIGNUM A)
{
	if(A.sig==-1)printf("-");
	for(int i=A.cnt;i>=1;i--)printf("%d",A.num[i]);printf("\n");
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
BIGNUM Trans(long long x)
{
	BIGNUM X;X.sig=1;X.cnt=0;X.num[1]=0;
	while(x)
	{
		X.num[++X.cnt]=x%10;
		x/=10;
	}
	if(X.cnt==0)X.cnt=1;
	while(X.cnt<N)X.num[++X.cnt]=0;
	return X;
} 
int MIN(int x,int y)
{
	if(x<y)return x;return y;
}
BIGNUM Times(BIGNUM A,BIGNUM B)
{
	BIGNUM X;X.sig=1;X.cnt=1;
	for(int i=1;i<=N+1;i++)X.num[i]=0;
	for(int i=1;i<=A.cnt;i++)
	{
		for(int j=1;j<=B.cnt;j++)
		{
			if(i+j-1>N)break;
			X.num[i+j-1]+=A.num[i]*B.num[j];
			if(X.num[i+j-1]>=10)
			{
				X.num[i+j]+=X.num[i+j-1]/10;
				X.num[i+j-1]%=10;
			}
		}
	}
	//for(int i=A.cnt+B.cnt+5;i>=1;i--)
	//if(X.num[i]!=0){X.cnt=i;break;}
	X.cnt=N;
	return X;
}
int main()
{
	int a,b;
	int ct=0,T;scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&a,&b,&N);
		BIGNUM A=Trans(a);BIGNUM B=A;
		for(int i=1;i<b;i++)A=Times(A,B);
		printf("case #%d:\n",ct++);
		print(A);
	}
	return 0;
}