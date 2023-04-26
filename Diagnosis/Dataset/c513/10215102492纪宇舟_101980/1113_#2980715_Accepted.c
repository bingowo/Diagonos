#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
char chr[1005];
typedef struct
{
	int sig,cnt;
	int num[1005];
}BIGNUM;
int MAX(int x,int y)
{
	if(x>y)return x;return y;
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
	return X;
} 
BIGNUM Add(BIGNUM A,BIGNUM B)
{
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
void print(BIGNUM A)
{
	if(A.sig==-1)printf("-");
	for(int i=A.cnt;i>=1;i--)printf("%d",A.num[i]);
}
int main()
{
	int k,n;BIGNUM a[101];
	scanf("%d%d",&k,&n);
	a[1]=Trans(0);a[2]=Trans(1);
	for(int i=3;i<=n;i++)
	{
		a[i]=Trans(0);
		for(int j=i-1;j>=i-k&&j>0;j--)a[i]=Add(a[i],a[j]);
	}
	print(a[n]);
	return 0;
} 