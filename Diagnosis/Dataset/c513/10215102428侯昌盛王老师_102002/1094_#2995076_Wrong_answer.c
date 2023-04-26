#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void*a,const void*b)
{
	char *p,*q;
	p=(char*)a;q=(char*)b;
	int lenp,lenq;
	lenp=strlen(p);lenq=strlen(q);
	if(lenp<lenq) return -1;
	else if(lenp>lenq) return 1;
	else{
		if(strcmp(p,q)<=0) return -1;
		else return 1;
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
	for(i=0;i<len;i++)
	{
		a[i]=s[n-1][i]-'0';
	}
	for(i=k;i>=0&&k2>=0;i--)
	{
		b[i]=s[0][k2--]-'0';
	}
	int carry=0;
	for(i=k;i>=0;i--)
	{
		a[i]-=carry;
		if(a[i]<b[i])
		{
			a[i]+=10;
			carry=1;
		}
		b[i]=a[i]-b[i];
	}
	for(i=0;b[i]==0;i++);

	for(i;i<=k;i++) printf("%d",b[i]);
	printf("\n");
	return 0;
}