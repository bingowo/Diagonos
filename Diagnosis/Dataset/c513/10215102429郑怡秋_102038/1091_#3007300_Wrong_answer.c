#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mul(int *a,int x,int len)
{
	int carry=0;
	if(x<0) a[0]*=-1,x=-x;
	for(int i=1;i<len;i++)
	{
		int n=a[i]*x+carry;
		a[i]=n%10;
		carry=n/10;
	}
	if(carry>0) a[len]=carry,len++;
	return len;
}
int jian(int *a,int *b,int *c,int k,int l)
{
	if(k<l) k=l;
	int carry=0;
	c[0]=1;
	for(int i=1;i<k;i++)
	{
		int x=a[i]-b[i]+carry;
		if(x<0)
		{
			c[i]=x+10;carry=-1;
		}
		else c[i]=x,carry=0;
	}
	if(carry<0)
	{
		c[0]=-1;
		c[k-1]-=10;carry=0;
		for(int i=1;i<k;i++) c[i]*=-1;
		for(int i=1;i<k;i++)
		{
			int x=c[i]+carry;
			if(c<0) c[i]=x+10,carry=-1;
			else c[i]=x,carry=0;
		}
	}
	return k;
}
int add(int *a,int *b,int *c,int k,int l)
{
	if(k<l) k=l;
	int carry=0;
	for(int i=1;i<k;i++)
	{
		int x=a[i]+b[i]+carry;
		c[i]=x%10;
		carry=x/10;
	}
	if(carry>0) c[k]=carry,k++;
	return k;
}
int f(int c,int K[],int P[],int a,int b, int L[],int k,int l)
{
	k=mul(P,a,k);
	l=mul(L,b,l);
	c=c*L[0];
	if(c==1&&P[0]==1) K[0]==1,k=add(P,L,K,k,l);
	else if(c==-1&&P[0]==1) k=jian(P,L,K,k,l);
	else if(c==1&&P[0]==-1) k=jian(L,P,K,k,l);
	else if(c==-1&&P[0]==-1) K[0]=-1,k=add(P,L,K,k,l);
	return k;
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

	int K[2000]={0},L[2000]={0};
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
	//for(int i=1;i<k;i++) printf("K:%d\n",K[i]);
	for(int i=1;i<n;i++)
	{
		int P[2000]={0};
		for(int j=0;j<k;j++) P[j]=K[j];
		int kk=k;
		k=f(-1,K,P,a,b,L,kk,l);
		l=f(1,L,P,b,a,L,kk,l);
	}//printf("K:%d %d",K[1],L[1]);
	
	while(K[k-1]==0) k--;
	while(L[l-1]==0) l--;
	int a1=k-1,a2=l-1;
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