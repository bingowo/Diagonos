#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void f(char c,int K[],int P[],int a,int b, int L[])
{
	int carry1=0,carry2=0;
	if(a<0) P[0]*=-1;
	if(b<0) L[0]*=-1;
	for(int i=1;i<1000;i++)
	{
		int x1=P[i]*a+carry1;
		P[i]=x1/10;
		carry1=x1%10;
		
		int x2=L[i]*b+carry2;
		L[i]=x2/10;
		carry2=x2%10;
		
	}
	int sign1=1,sign2=1;
	if(c=='+') sign1*=P[0],sign2*=L[0];
	if(c=='-') sign1*=P[0],sign2*=L[0]*-1;
	if(sign1*sign2==1)
	{
		K[0]=sign1;int carry=0;
		for(int i=1;i<1000;i++)
		{
			int x=P[i]+L[i]+carry;
			P[i]=x/10;
			carry=x%10;
		}
	}
	else if(sign1*sign2==-1)
	{
		int a1=1000,a2=1000,carry=0;
		while(P[a1]==0&&a1>=1) a1--;
		while(L[a2]==0&&a2>=1) a2--;
		if(a1>a2)
		{
			for(int i=1;i<1000;i++){
			int x=P[i]-L[i]+carry;
			if(x<0) K[i]=x+10,carry=-1;
			else K[i]=x,carry=0;
			K[0]*=sign1;}
		}
		else if(a1<a2)
		{
			for(int i=1;i<1000;i++){
			int x=L[i]-P[i]+carry;
			if(x<0) K[i]=x+10,carry=-1;
			else K[i]=x,carry=0;
			K[0]*=sign2;}
		}
		else
		{
			while(P[a1]==L[a2]&&a1>=1&&a2>=1) a1--,a2--;
			if(P[a1]>L[a2])
			{
				for(int i=1;i<1000;i++){
				int x=P[i]-L[i]+carry;
				if(x<0) K[i]=x+10,carry=-1;
				else K[i]=x,carry=0;
				K[0]*=sign1;}
			}
			else if(P[a1]<L[a2])
			{
				for(int i=1;i<1000;i++){
				int x=L[i]-P[i]+carry;
				if(x<0) K[i]=x+10,carry=-1;
				else K[i]=x,carry=0;
				K[0]*=sign2;}
			}
		}
	}
}

void pri(int K[],int a)
{
	if(K[0]==-1) printf("-");
	for(int i=1;i<=a;i++) printf("%d",K[i]);
}
int main()
{
	long long a=0,b=0,n=0;
	char c;
	
	scanf("%lld",&a);//a 
	
	c=getchar();//printf("%c\n",c);
	if(c=='-') 
	{
		scanf("%lld",&b);//b
		if(b==0) b=-1;
		else b=-b;
	}
	else if(c=='+')
	{
		scanf("%d",&b);//b
		if(b==0) b=1;	
	}
	else if(c=='i')
	{
		if(a==0) b=1;
		else b=a,a=0;
	}
	if(b!=0) getchar();
	scanf("%d",&n);//n
	//printf("%d %d %d",a,b,n);
//	long long k=a,l=b;
//	for(int i=1;i<n;i++)
//	{
//		long long p=k;
//		k=p*a-b*l; 
//		l=p*b+l*a;
//	}
//	a=k;b=l;

	int K[1000]={0},L[1000]={0};
	K[0]=1;L[0]=1;
	if(a<0) K[0]=-1;
	if(b<0) L[0]=-1;
	int aa=a,bb=b,k=1,l=1;
	while(aa>0)
	{
		K[k++]=aa%10;
		aa/=10;
	}
	while(bb>0)
	{
		L[l++]=bb%10;
		bb/=10;
	}
	for(int i=1;i<n;i++)
	{
		int P[1000]={0};
		for(int j=1;j<1000;j++) P[j]=K[j];
		f('-',K,P,a,b,L);
		f('+',L,P,b,a,L);
	}//printf("K:%d %d",K[1],L[1]);
	int a1=1000,a2=1000;
	while(K[a1]==0&&a1>=1) a1--;
	while(L[a2]==0&&a2>=1) a2--;
	if(n==0) printf("1\n");
	else if(a2==1&&L[a2]==0) pri(K,a1);
	else if(a1==1&&K[a1]==0) {
		if(a2==1&&L[a2]==1) printf("i");
		else if(a2==1&&L[a2]==-1) printf("-i");
		else if(a2==1&&L[a2]==0) printf("0");
		else pri(L,a2),printf("i");
	}
	else if(a2==1&&L[a2]==1) pri(K,a1),printf("+i");
	else if(a2==1&&L[a2]==-1) pri(K,a1),printf("-i");
	else if(K[0]>0&&L[0]>0 ||(K[0]<0&&L[0]>0)) pri(K,a1),printf("+"),pri(L,a2),printf("i");
	else if(K[0]<0&&L[0]<0 ||(K[0]>0&&L[0]<0)) pri(K,a1),pri(L,a2),printf("i");
	
	return 0;
}