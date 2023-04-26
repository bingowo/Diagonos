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
void print(BIGNUM A)
{
	if(A.sig==-1)printf("-");
	for(int i=A.cnt;i>=1;i--)printf("%d",A.num[i]);
}
int main()
{
    long long bin[5],flag=0;
    scanf("%s",chr);
    int L=strlen(chr);
    BIGNUM a,b,qr,qi,X;
    a.sig=1;b.sig=1;qr.sig=1;qi.sig=1;
    a.cnt=1;a.num[1]=0;b.cnt=1;b.num[1]=0;
    qr.cnt=1;qr.num[1]=1;qi.cnt=1;qi.num[1]=0;
    for(int i=2;i<L;i++)
    {
        int x;
        if(chr[i]>='0'&&chr[i]<='9')x=chr[i]-'0';
        else x=chr[i]-'A'+10;
        for(int j=4;j>=1;j--){bin[j]=x%2;x/=2;}
        for(int j=1;j<=4;j++)
        {
            if(i==2&&bin[j]==0&&flag==0)continue;
            if(i==2&&bin[j]==1&&flag==0){flag=1;continue;}
            X.cnt=1;X.sig=1;X.num[1]=bin[j];
            a=Minus(X,qr);a=Minus(a,qi);b=Minus(qr,qi);
            qr=a;qi=b;
        }
    }
    if(L==3&&chr[2]=='1'){printf("1");return 0;}
    if(a.cnt==1&&a.num[1]==0&&b.cnt==1&&b.num[1]==0){printf("0");return 0;}
    if(a.cnt!=1||a.num[1]!=0)if(b.sig>0&&(b.cnt!=1||b.num[1]!=0)){print(a);printf("+");}else print(a);/*printf("%lld",a);/*printf("%lld+",a);*/
    if(b.cnt!=1||b.num[1]!=0)if(b.sig==1&&b.cnt==1&&b.num[1]==1)printf("i");else if(b.sig==-1&&b.cnt==1&&b.num[1]==1)printf("-i");else {print(b);printf("i");};
    return 0;
}