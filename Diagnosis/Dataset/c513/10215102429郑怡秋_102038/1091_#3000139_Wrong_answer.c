#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void mul(int *a,int x)
{
	int carry=0;
	if(x<0) a[0]*=-1,x=-x;
	for(int i=1;i<900;i++)
	{
		int n=a[i]*x+carry;
		a[i]=n%10;
		carry=n/10;
	}
}
void jian(int *a,int *b,int *c)
{
	int carry=0;
	for(int i=1;i<900;i++)
	{
		int x=a[i]-b[i]+carry;
		if(x<0)
		{
			c[i]=x+10;carry=-1;
		}
		else c[i]=x,carry=0;
	}
}
void add(int *a,int *b,int *c)
{
	int carry=0;
	for(int i=1;i<900;i++)
	{
		int x=a[i]+b[i]+carry;
		c[i]=x%10;
		carry=x/10;
	}
}
void f(char c,int K[],int P[],int a,int b, int L[])
{
	mul(P,a);
	mul(L,b);
	if(c=='+'&&P[0]==1&&L[0]==1 || c=='-'&&P[0]==1&&L[0]==-1) K[0]==1,add(P,L,K);
	else if(c=='+'&&P[0]==1&&L[0]==-1 || c=='-'&&P[0]==1&&L[0]==1)
	{
		K[0]=1;
		jian(P,L,K);
		int i=900;
		while(K[i]==0&&i>1) i--;
		if(K[i]==-1) K[0]=-1,jian(L,P,K);
	}
	else if(c=='+'&&P[0]==-1&&L[0]==1 || c=='-'&&P[0]==-1&&L[0]==-1)
	{
		K[0]=1;
		jian(L,P,K);
		int i=900;
		while(K[i]==0&&i>1) i--;
		if(K[i]==-1) K[0]=-1,jian(L,P,K);
	}
	else if(c=='+'&&P[0]==-1&&L[0]==-1 || c=='-'&&P[0]==-1&&L[0]==1) K[0]=1,add(P,L,K);

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
		K[k++]=aa%10;//printf("%d\n",K[k-1]);
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
		for(int j=0;j<1000;j++) P[j]=K[j];
		f('-',K,P,a,b,L);
		f('+',L,P,b,a,L);
	}//printf("K:%d %d",K[1],L[1]);
	int a1=900,a2=900;
	while(K[a1]==0&&a1>1) a1--;
	while(L[a2]==0&&a2>1) a2--;
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