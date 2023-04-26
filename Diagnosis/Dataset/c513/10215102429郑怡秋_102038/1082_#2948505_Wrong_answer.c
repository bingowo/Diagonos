#include <stdio.h>
#include <stdlib.h>
int f(int a[],int b[],int i2,int j2,int n)//小数部分相加 
{
	int carry=0;
	int x;
	if(i2<j2) i2=j2; 
	for(int i=i2-1;i>=0;i--)
	{
//		if(i>j2-1) x=0;
//		else x=b[i];
		x=b[i]+a[i]+carry;
		if(x>10)
		{
			a[i]=x%10;
			carry=x/10;
		}
		else 
		{
			a[i]=x;
			carry=0;
		}
	}
	int c=0;
	if(n<i2)
	{
		if(a[n]>=5) 
		{
			int i=n-1;
			while(a[i]+1>=10&&i>=0) a[i]=a[i]-9,i--;
			a[i]+=1;
			if(i<0) c=1;
			else c=0;
		}	
	}
	return carry+c;
}
int g(int a[],int b[],int i,int j)
{
	int carry=0;
	for(int k=1;k<=((i>j)?i:j);k++)
	{	//printf("%d\n",k); 
		int l=b[j-k];
		if(j-k<0) l=0;
		int p=a[i-k];
		if(i-k<0) p=0;
		int n=p+l+carry;
		if(n>=10)
		{
			a[i-k]=n%10;
			carry=n/10;
		}
		else
		{
			a[i-k]=n;
			carry=0;
		}
		//printf("%d\n",a[i-k]);
	}
	return carry;
}
int main()
{
	int a[501],b[501],c[501],d[501];
	for(int i=0;i<501;i++) a[i]=0,b[i]=0,c[i]=0,d[i]=0;
	int n,i1=0,i2=0,j1=0,j2=0;
	char r;
	
	while((r=getchar())!='.'&&r!=' ') a[i1++]=r-'0';
	if(r=='.')	while((r=getchar())!=' ') b[i2++]=r-'0';
	while((r=getchar())!='.') c[j1++]=r-'0';
	while((r=getchar())!=' ') d[j2++]=r-'0';
	scanf("%d",&n);
	int carry=0;
	carry=f(b,d,i2,j2,n);
	a[i1-1]+=carry;//printf("%d\n",a[i1-1]);
	carry=g(a,c,i1,j1);
	
	
	if(carry>0)
	{
		int x2=n;
		printf("%d",carry);
		for(int i=0;i<i1;i++) printf("%d",a[i]);
		//if(a[0]=='0') printf("0");
		printf(".");
		for(int i=0;i<n;i++) printf("%d",b[i]);
		printf("\n");
	}
	else 
	{
		int x1=0,x2=n;
		while(a[x1++]==0);
		if(x1-1>=i1) printf("0"); 
		for(int i=x1-1;i<i1;i++) printf("%d",a[i]);
		printf(".");
		for(int i=0;i<n;i++) printf("%d",b[i]);
		printf("\n");
	}
	
	
	return 0;
}