#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int aodd(int B[],int D[],int l,int n)
{
	int carry=0;
	for(int i=l-1;i>=0;i--)
	{
		int x=B[i]+D[i]+carry;
		if(x>=10) B[i]=x%10,carry=x/10;
		else B[i]=x,carry=0;
	}
	int c=0;
	if(B[n]>=5) 
		{
			int i=n-1;
			while(i>=0&&B[i]+1>=10) B[i]=B[i]-9,i--;
			//printf("i:%d\n",i);
			if(i<0) c=1;
			else B[i]+=1,c=0;
		}
	return carry+c;
}
void add(int A[],int C[],int l)
{
	
	int carry=0;
	for(int i=0;i<l;i++)
	{
		int x=A[i]+C[i]+carry;
		if(x>=10) A[i]=x%10,carry=x/10;
		else A[i]=x,carry=0;
	}
	A[l]=carry;//printf("%d\n",A[l]);
}

int main()
{
	char a[10000]={0},b[10000]={0};
	int n;
	scanf("%s%s%d",a,b,&n);
	int l1=strlen(a),l2=strlen(b);
	int k1=0,k2=0;
	while(a[k1]!='.'&&k1<l1) k1++;
	while(b[k2]!='.'&&k2<l2) k2++;
	int A[10000],B[10000],C[10000],D[10000];
	for(int i=0;i<10000;i++) A[i]=0,B[i]=0,C[i]=0,D[i]=0;
	if(k1<l1&&k2<l2)
	{
		for(int i=k1-1,j=0;i>=0;i--,j++) A[j]=a[i]-'0';
		for(int i=k2-1,j=0;i>=0;i--,j++) C[j]=b[i]-'0';
		for(int i=k1+1,j=0;i<l1;i++,j++) B[j]=a[i]-'0';
		for(int i=k2+1,j=0;i<l2;i++,j++) D[j]=b[i]-'0';
	}
	else if(k1==l1&&k2<l2)
	{
		for(int i=l1-1,j=0;i>=0;i--,j++) A[j]=a[i]-'0';
		for(int i=k2-1,j=0;i>=0;i--,j++) C[j]=b[i]-'0';
		for(int i=k2+1,j=0;i<l2;i++,j++) D[j]=b[i]-'0';
	}
	else if(k1<l1&&k2==l2)
	{
		for(int i=k1-1,j=0;i>=0;i--,j++) A[j]=a[i]-'0';
		for(int i=k1+1,j=0;i<l1;i++,j++) B[j]=a[i]-'0';
		for(int i=l2-1,j=0;i>=0;i--,j++) C[j]=b[i]-'0';
	}
	int la=k1,lb=l1-k1,lc=k2,ld=l2-k2;
	if(lb<ld) lb=ld;
	int carry=aodd(B,D,lb,n);
	A[0]+=carry;
	if(la<lc) la=lc;
	add(A,C,la);
	while(A[la]==0&&la>=0) la--;
	if(la<0) printf("0");
	else for(int i=la;i>=0;i--) printf("%d",A[i]);
	printf(".");
	for(int i=0;i<n;i++) printf("%d",B[i]);
	return 0;
		
} 