#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
	int sig,cnt;
	int num[105];
}BIGNUM;
void print(BIGNUM A)
{
	if(A.sig==-1)printf("-");
	for(int i=A.cnt;i>=1;i--)printf("%d",A.num[i]);//printf("\n");
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
	return X;
} 
BIGNUM Times(BIGNUM A,BIGNUM B)
{
	BIGNUM X;X.sig=1;X.cnt=1;
	for(int i=1;i<=A.cnt+B.cnt+5;i++)X.num[i]=0;
	for(int i=1;i<=A.cnt;i++)
	{
		for(int j=1;j<=B.cnt;j++)
		{
			X.num[i+j-1]+=A.num[i]*B.num[j];
			if(X.num[i+j-1]>=10)
			{
				X.num[i+j]+=X.num[i+j-1]/10;
				X.num[i+j-1]%=10;
			}
		}
	}
	for(int i=A.cnt+B.cnt+5;i>=1;i--)
	if(X.num[i]!=0){X.cnt=i;break;}
	return X;
}
char s[1005];
int main()
{
	scanf("%s",s);
	int n=strlen(s);
	BIGNUM ANS=Trans(1);
	for(int i=0;i<n;i++)
	{
		if(n==1)break;
		int x=0;
		if(i==0)
		{
			if(s[i]!=s[i+1])x=2;
			else x=1;
		}
		else if(i==n-1)
		{
			if(s[i]!=s[i-1])x=2;
			else x=1;
		}
		else
		{
			if(s[i]!=s[i-1]&&s[i]!=s[i+1]&&s[i-1]!=s[i+1])x=3;
			else if(s[i]==s[i-1]&&s[i]==s[i+1])x=1;
			else x=2;
		}
		ANS=Times(ANS,Trans(x));
	}
	print(ANS);
}