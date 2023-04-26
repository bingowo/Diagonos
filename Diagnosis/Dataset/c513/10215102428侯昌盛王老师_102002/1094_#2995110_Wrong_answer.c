#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void add(int *a,int*b,int n)
{
	int carry=0,i;
	for(i=n;i>=0;i--)
	{
		a[i]=a[i]+carry+b[i];
		carry=a[i]/10;
		a[i]=a[i]%10;
	}
}
void m(int *a,int*b,int n)
{
	int i;
	int carry=0;
	for(i=n;i>=0;i--)
	{
		a[i]-=carry;
		if(a[i]<b[i])
		{
			a[i]+=10;
			carry=1;
		}
		b[i]=a[i]-b[i];
	}
} 
int cmp(const void*a,const void*b)
{
	char *p,*q;
	p=(char*)a;q=(char*)b;
	int lenp,lenq;
	lenp=strlen(p);lenq=strlen(q);
	if(*p=='-'&&*q!='-') return -1;
	else if(*p!='-'&&*q=='-') return 1;
	else if(*p!='-'&&*p!='-'){
		if(lenp<lenq) return -1;
		else if(lenp>lenq) return 1;
		else{
			if(strcmp(p,q)<=0) return -1;
			else return 1;
		}
	}
	else if(*p=='-'&&*q=='-')
	{
		if(lenp<lenq) return 1;
		else if(lenp>lenq) return -1;
		else{
			if(strcmp(p,q)<0) return 1;
			else return -1;
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	char s[n][121];
	int i=0;
	for(i;i<n;i++) scanf("%s",s[i]);
	qsort(s,n,sizeof(s[0]),cmp);
	
	int a[121]={0},b[121]={0},len,k,len2,k2;
	len=strlen(s[n-1]);
	len2=strlen(s[0]);
	k=len-1;
	k2=len2-1;
	if(s[0][0]!='-'&&s[n-1][0]!='-'){
	
		for(i=0;i<len;i++)
		{
			a[i]=s[n-1][i]-'0';
		}
		for(i=k;i>=0&&k2>=0;i--)
		{
			b[i]=s[0][k2--]-'0';
		}
		m(a,b,len-1);
	}
	else if(s[0][0]=='-'&&s[n-1][0]=='-')
	{
		for(i=0;i<len2-1;i++)
		{
			a[i]=s[0][i+1]-'0';
		}
		for(i=k2;i>=0&&k2>=1;i--)
		{
			b[i]=s[n][k2--]-'0';
		}
		m(a,b,len2-1);
	}
	else if(s[0][0]=='-'&&s[n-1][0]!='-')
	{
		for(i=1;i<len;i++)
		{
			a[i]=s[n-1][i]-'0';
		}
		for(i=1;i<len2;i++)
		{
			b[i]=s[0][i]-'0';
		}
		int max;
		if(len>len2) max=len;
		else max=len2;
		add(a,b,max-1);
	}

	
	for(i=0;b[i]==0;i++);

	for(i;i<=k;i++) printf("%d",b[i]);
	printf("\n");
	return 0;
}