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
		if(x>=10)
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
			while(i>=0&&a[i]+1>=10) a[i]=a[i]-9,i--;
			//printf("i:%d\n",i);
			if(i<0) c=1;
			else a[i]+=1,c=0;
		}	
	}//printf("%d\n",carry+c);
	return carry+c;
}
int g(int a[],int b[],int i,int j)
{
	int carry=0;
	int an=((i>j)?i:j);//printf("%d\n",a[k]);
	if(a[0]==0) for(int k=0;k<j;k++) a[k]=b[k];
	else
	for(int k=1;k<=an;k++)
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
	}//printf("%d\n",a[0]);
	return carry;
}
int main()
{
	int a[10001],b[10001],c[10001],d[10001];
	for(int i=0;i<10001;i++) a[i]=0,b[i]=0,c[i]=0,d[i]=0;
	int n,i1=0,i2=0,j1=0,j2=0;
	char r;
	
	while((r=getchar())!='.'&&r!=' ') a[i1++]=r-'0';
	if(r=='.')  while((r=getchar())!=' ') b[i2++]=r-'0';
	while((r=getchar())!='.'&&r!=' ') c[j1++]=r-'0';//printf("%d\n",c[j1-1]);
	if(r=='.')  while((r=getchar())!=' ') d[j2++]=r-'0';
	scanf("%d",&n);
	int cary=0;
	cary=f(b,d,i2,j2,n);
	a[i1-1]+=cary;//printf("%d\n",a[i1-1]);
	int carry=g(a,c,i1,j1);
	
	//printf("%d\n",carry);
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
		if(x1-1>=i1) 
		{
			if(a[x1-1]==0)  printf("0");
			else i1++,printf("%d",cary);
		} 
		//printf("%d\n",x1);
		for(int i=x1-1;i<i1;i++) printf("%d",a[i]);
		printf(".");
		for(int i=0;i<n;i++) printf("%d",b[i]);
		printf("\n");
	}
	
	
	return 0;
}