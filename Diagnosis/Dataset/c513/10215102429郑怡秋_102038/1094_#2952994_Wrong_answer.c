#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	char s[130];
}qwq;
int cmp(const void *a,const void *b)
{
	qwq*p1=(qwq*)a;qwq*p2=(qwq*)b;
	if(strlen(p1->s)<strlen(p2->s)) return -1;
	else if(strlen(p1->s)>strlen(p2->s)) return 1;
	else 
	{
		return strcmp(p1->s,p2->s);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	qwq*p=(qwq*)malloc(n*sizeof(qwq));
	for(int i=0;i<n;i++) scanf("%s",p[i].s);
	qsort(p,n,sizeof(p[0]),cmp);
	int a[120];
	int l1=strlen(p[0].s),l2=strlen(p[n-1].s);
	for(int i=0;i<l1;i++) a[i]=p[n-1].s[l2-1-i]-p[0].s[l1-1-i];//printf("%d\n",a[i])
	for(int i=l1;i<l2;i++) a[i]=p[n-1].s[l2-1-i]-'0';//printf("%d\n",a[i])
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
	for(int i=l2-1;i>=0;i--) printf("%d",a[i]);
	printf("\n");
	free(p);
	return 0;
}