#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
	int sig,cnt;
	int num[105];
}BIGNUM;
BIGNUM MI[41];
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
int fla=0;
BIGNUM Minus(BIGNUM A,BIGNUM B)
{
	BIGNUM X=B,Y=A;
	if(CMP(A,B)==-1)printf("Jeez ");
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
	A.cnt=CNT;
	//for(int i=1;i<=A.cnt;i++)if(A.num[i]<0&&fla==0){print(Y);print(X);printf("fuck\n");fla=1;};
	return A;
}
BIGNUM ANS;
BIGNUM Div(BIGNUM A,BIGNUM B)
{
	//print(A);print(B);
	BIGNUM X;X.sig=1;ANS.sig=1;ANS.cnt=0;ANS.num[1]=0;X.cnt=0;
	memset(ANS.num,0,sizeof(ANS.num));
	int apos=A.cnt;//print(A);print(B);
	while(apos>=1)
	{
		while(X.cnt<B.cnt&&apos>=1)
		{
			X.cnt++;
			for(int i=X.cnt;i>1;i--)X.num[i]=X.num[i-1];
			X.num[1]=A.num[apos--];//printf("fuck:%d\n",A.num[apos+1]);
			ANS.num[++ANS.cnt]=0;
			//if(A.num[i]<0&&fla==0){print(A);print(X);printf("fuck\n");fla=1;};
		}
		if(X.cnt<B.cnt)break;
		//X.cnt=B.cnt;//ANS.num[++ANS.cnt]=0;
		//print(X);
		if(CMP(X,B)==-1)
		{
			ANS.num[++ANS.cnt]=0;BIGNUM Y=X;
			X=Times(Trans(10LL),X);X.num[1]+=A.num[apos--];
			//for(int i=1;i<=X.cnt;i++)if(X.num[i]<0&&fla==0){print(X);print(Y);printf("fuck\n");fla=1;};
		}
		//print(X);
		while(CMP(X,B)==1)
		{X=Minus(X,B);ANS.num[ANS.cnt]++;}
		//printf("%d\n",ANS.num[ANS.cnt]);
		//print(X);
		//printf("fuck%d\n",X.num[X.cnt]);
		if(CMP(X,B)==0)
		{X=Minus(X,B);X.cnt=0;ANS.num[ANS.cnt]++;}
		int flag=0;
	}
	int pos=0;//printf("%d\n",ANS.cnt);//ANS.cnt--;
	//print(ANS);
	for(int i=1;i<=ANS.cnt;i++)if(ANS.num[i]!=0){pos=i;break;}
	for(int i=pos;i<=ANS.cnt;i++)ANS.num[i-pos+1]=ANS.num[i];ANS.cnt-=pos-1;
	for(int i=1;i<=ANS.cnt/2;i++)
	{
		int t=ANS.num[i];ANS.num[i]=ANS.num[ANS.cnt-i+1];ANS.num[ANS.cnt-i+1]=t;
	}
	return ANS;
} 
BIGNUM Cal(int x)
{
	if(MI[x].sig!=-1)return MI[x];
	MI[x]=Times(Cal(x-1),Trans(x));
	return MI[x];
}
BIGNUM trans(char s[])
{
	int n=strlen(s);
	BIGNUM X;X.sig=1;X.cnt=0;
	for(int i=n-1;i>=0;i--)X.num[++X.cnt]=s[i]-'0';
	return X;
}
int main()
{
	char s1[105]="121645100408832000",s2[105]="1609445376000";
	long long x,y;int T,t=0;
	MI[0].sig=1;MI[0].cnt=1;MI[0].num[1]=1;
	for(int i=1;i<=40;i++)MI[i].sig=-1;
	//print(Div(Trans(6666),Trans(33)));
	//print(Cal(40));
	//print(Times(Cal(20),Cal(20)));
	//print(Minus(Trans(4355347545687),Trans(23345345346)));
	//print(Div(Cal(19),Times(Cal(11),Cal(8))));
	//print(Div(trans(s1),trans(s2)));
	//print(Times(Cal(7),Cal(8)));
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld",&x,&y);
		//print(Trans(x));printf(" ");print(Trans(y));printf("\n");
		//print(Div(Trans(x),Trans(y)));
		//print(Cal(x));print(Cal(y));
		printf("case #%d:\n",t++);
		//BIGNUM X=Cal(x);BIGNUM Y=Cal(y);BIGNUM Z=Cal(x-y);//print(Y);
		//Y=Times(Y,Z);print(Y);print(X);print(Div(X,Y));
		print(Div(Cal(x),Times(Cal(x-y),Cal(y))));
	}
	return 0;
}