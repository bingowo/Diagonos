#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
	int sig,cnt;
	int num[4005];
}BIGNUM;
int MAX(int x,int y)
{
	if(x>y)return x;return y;
}
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
BIGNUM Trans(int x)
{
	BIGNUM X;X.sig=1;X.cnt=0;X.num[1]=0;
	if(x<0)
	{
		X.sig=-1;x=-x;
	}
	while(x)
	{
		X.num[++X.cnt]=x%10;
		x/=10;
	}
	if(X.cnt==0)X.cnt=1;
	return X;
} 
BIGNUM Minus(BIGNUM A,BIGNUM B);
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
		//printf("%d %d %d\n",i,A.num[i],B.num[i]);
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
BIGNUM Times(BIGNUM A,BIGNUM B)
{
	
	BIGNUM X;X.sig=1;X.cnt=1;
	if((A.sig>0&&B.sig<0)||(A.sig<0&&B.sig>0))X.sig=-1;
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
	if(X.num[i]!=0){X.cnt=i;break;}//print(A);print(B);print(X);
	return X;
}
int main()
{
	char c,s[100];
	int n,sig1=0,sig2=0,a=0,b=0,x=0,sig=0;
	scanf("%s",s);
	int len=strlen(s);
	if(len>1)
	{
		if(s[0]>='0'&&s[0]<='9')
		{sig=1;x=s[0]-'0';}
		if(s[0]=='-')sig=-1;
		for(int i=1;i<len;i++)
		{
			if(s[i]=='-'||s[i]=='+')
			{
				a=x*sig;x=0;
				if(s[i]=='-')sig=-1;
				else sig=1;
			}
			if(s[i]>='0'&&s[i]<='9')
			x=x*10+s[i]-'0';
			if(i==len-1)
			{
				if(s[i]=='i')
				{
					if(x==0)b=sig;
					else b=sig*x;
				}
				else
				{
					a=x*sig;
				}
			}
		}
	}
	else 
	{
		if(s[0]>='0'&&s[0]<='9')a=s[0]-'0';
		else b=1;
	}
	BIGNUM A=Trans(a),B=Trans(b),TA=A,TB=B,X,Y;
	scanf("%d",&n);
	if(n==0){printf("1");return 0;}
	for(int i=1;i<n;i++)
	{
		X=Times(A,TA);Y=Times(B,TB);
		//print(A);printf(" ");print(Times(A,TB));printf("\n");
		B=Add(Times(A,TB),Times(B,TA));
		A=Minus(X,Y);
	}
	if(A.cnt>1||A.num[1]!=0)print(A);
	if(B.cnt>1||B.num[1]!=0)
	{
		if(B.sig>0&&(A.cnt>1||A.num[1]!=0))printf("+");
		if(B.cnt>1||B.num[1]!=1)print(B);
		else if(B.sig==-1)printf("-");
		printf("i");
	}
	return 0;
}