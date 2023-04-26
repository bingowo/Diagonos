#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	char s[130];
}qwq;
int cmp(const void *a,const void *b)
{
	qwq*p1=(qwq*)a;qwq*p2=(qwq*)b;
	if(p1->s[0]=='-'&&p2->s[0]=='-')
	{
		if(strlen(p2->s)<strlen(p1->s)) return -1;
		else if(strlen(p2->s)>strlen(p1->s)) return 1;
		else 
		{
			return strcmp(p2->s,p1->s);
		}
	}
	else if(p1->s[0]!='-'&&p2->s[0]!='-')
	{
		if(strlen(p1->s)<strlen(p2->s)) return -1;
		else if(strlen(p1->s)>strlen(p2->s)) return 1;
		else 
		{
			return strcmp(p1->s,p2->s);
		}
	}
	else if(p1->s[0]!='-'&&p2->s[0]=='-')
	{
		return 1;
	}
	else if(p1->s[0]=='-'&&p2->s[0]!='-')
	{
		return -1;
	}
}
void minu(int a[],char smin[],char smax[],int l1,int l2)
{
	for(int i=0;i<l1;i++) a[i]=smax[l2-1-i]-smin[l1-1-i];//printf("%d\n",a[i])
	for(int i=l1;i<l2;i++) a[i]=smax[l2-1-i]-'0';//printf("%d\n",a[i])
	int carry=0;
	for(int i=0;i<l2;i++)
	{
		int x=a[i]+carry;
		if(x<0)
		{
			a[i]=x+10;
			carry=-1;
		}
		else
		{
			a[i]=x;
			carry=0;
		}
	}
}
void add(int a[],char smin[],char smax[],int l1,int l2)
{	
	int l=(l1>l2)?l1:l2;
	int carry=0;
	for(int i=0;i<l;i++)
	{
		int k1=0,k2=0;
		if(l2-1-i>=0) k2=smax[l2-1-i]-'0';
		if(l1-i-1>=1) k1=smin[l1-1-i]-'0'; 
		int x=k1+k2+carry;
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
		
	}if(carry>0) a[i]=carry;
}
int main()
{
	int n;
	scanf("%d\n",&n);
	qwq*p=(qwq*)malloc(n*sizeof(qwq));
	for(int i=0;i<n;i++) scanf("%s",p[i].s);
	qsort(p,n,sizeof(p[0]),cmp);
	
	//printf("%s\n%s\n",p[0].s,p[n-1].s);
	
	int a[120];
	for(int i=0;i<120;i++) a[i]=0;
	int l1=strlen(p[0].s),l2=strlen(p[n-1].s);
	if(p[n-1].s[0]=='-'&&p[0].s[0]=='-')
	{
		minu(a,p[n-1].s,p[0].s,l2,l1);
	}
	else if(p[n-1].s[0]!='-'&&p[0].s[0]!='-')
	{
		minu(a,p[0].s,p[n-1].s,l1,l2);
	}
	else if(p[n-1].s[0]!='-'&&p[0].s[0]=='-')
	{
		add(a,p[0].s,p[n-1].s,l1,l2);
	}
	
	

	
	int tump=119;
	while(a[tump]==0) tump--;
	for(int i=tump;i>=0;i--) printf("%d",a[i]);
	printf("\n");
	free(p);
	return 0;
}