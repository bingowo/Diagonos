#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
	int sig,cnt;
	int num[125];
}BIGNUM;
int MAX(int x,int y)
{
	if(x>y)return x;return y;
}
void print(BIGNUM A)
{
	if(A.sig==-1)printf("-");
	for(int i=A.cnt;i>=1;i--)printf("%d",A.num[i]);printf("\n");
}
int CMP(const void* a,const void* b)
{
	BIGNUM A=*(BIGNUM*)a;BIGNUM B=*(BIGNUM*)b;
	if(A.sig<0&&B.sig>0)return -1;
	if(A.sig>0&&B.sig<0)return  1;
	if(A.sig<0&&B.sig<0)
	{
		BIGNUM T=A;A=B;B=T;
	}
	if(A.cnt>B.cnt)return  1;
	if(A.cnt<B.cnt)return -1;
	for(int i=A.cnt;i>=1;i--)
	if(A.num[i]<B.num[i])return -1;
	else if(A.num[i]>B.num[i])return 1;
	return 0;
}
BIGNUM trans(char s[])
{
	int n=strlen(s);
	BIGNUM X;X.sig=1;X.cnt=0;
	int end=0;
	if(s[0]=='-')
	{
		X.sig=-1;end=1;
	}
	for(int i=n-1;i>=end;i--)X.num[++X.cnt]=s[i]-'0';
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
	//if(CMP(&A,&B)==-1)
	//{X=A;A=B;B=X;A.sig=-1;}
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
	BIGNUM a[51];
	char s[125];
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		a[i]=trans(s);
	}
	qsort(a+1,n,sizeof(BIGNUM),CMP);
	print(Minus(a[n],a[1]));
	return 0;
}