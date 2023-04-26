#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void add(int *a,int*b)
{
	int carry=0,i;

	for(i=120;i>=0;i--)
	{
		a[i]=a[i]+carry+b[i];
		//printf("%d\n",a[i]);
		carry=a[i]/10;
		a[i]=a[i]%10;
		//printf("%d\n",a[1]);
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
			b[i]=a[i]-b[i];
		}
		else
		{
			b[i]=a[i]-b[i];
			carry=0;
		}
		
	}
	//printf("%d\n",b[1]);
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
	//printf("%c %c\n",s[0][1],s[2][0]);
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
		for(i=0;b[i]==0;i++);
		for(i;i<=k;i++) printf("%d",b[i]);
	}
	else if(s[0][0]=='-'&&s[n-1][0]=='-')
	{
		for(i=0;i<len2-1;i++)
		{
			a[i]=s[0][i+1]-'0';
		
		}
		for(i=k2-1;i>=0&&k>=1;i--)
		{
			b[i]=s[n-1][k--]-'0';
		
		}
		m(a,b,len2-2);
		for(i=0;b[i]==0;i++);
		for(i;i<len2-1;i++) printf("%d",b[i]);
	}
	else if(s[0][0]=='-'&&s[n-1][0]!='-')
	{
		int k3=len2-1;
		int k4=len-1;
		
		for(i=120;i>=0&&k4>=0;i--)
		{
			a[i]=s[n-1][k4--]-'0';
		
		}
		for(i=120;i>=0&&k3>0;i--)
		{
			b[i]=s[0][k3--]-'0';
		
		}
		//printf("%d %d\n",a[1],b[1]);
	

		add(a,b);

		for(i=0;a[i]==0;i++);
		for(i;i<=120;i++) printf("%d",a[i]);
	}

	
	
	printf("\n");
	return 0;
}