#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
typedef struct
{
	int sig,cnt;
	int num[1005];
}BIGNUM;
int CMP(BIGNUM A,BIGNUM B)
{
	if(A.cnt>B.cnt)return  1;
	if(A.cnt<B.cnt)return -1;
	for(int i=A.cnt;i>=1;i--)
	if(A.num[i]<B.num[i])return -1;
	else if(A.num[i]>B.num[i])return 1;
}
int MAX(int x,int y)
{
	if(x>y)return x;return y;
}
BIGNUM Add(BIGNUM A,BIGNUM B)
{
	int n=MAX(A.cnt,B.cnt);
	for(int i=1;i<=n;i++)
	{
		A.num[i]+=B.num[i];
		if(A.num[i]>10)
		{
			A.num[i]-=10;A.num[i+1]+=1;
		}
	}
	int CNT=1;
	for(int i=n+1;i>=1;i--)
	if(A.num[i]!=0){CNT=i;break;}
	A.cnt=CNT;return A;
}
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
int main()
{
	BIGNUM A,B;
	char s[1005];int n;
	while(scanf("%s",s)!=EOF)
	{
		n=strlen(s);
		for(int i=0;i<n;i++)
		A.num[n-i]=s[i]-'0';
		A.cnt=n;A.sig=1;
		scanf("%s",s);n=strlen(s);
		for(int i=0;i<n;i++)
		B.num[n-i]=s[i]-'0';
		B.cnt=n;B.sig=1;//printf("%d %d\n",A.cnt,B.cnt);
		A=Minus(A,B);if(A.sig==-1)printf("-");
		for(int i=A.cnt;i>=1;i--)printf("%d",A.num[i]);
		printf("\n");
	}
	return 0;
}