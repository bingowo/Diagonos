#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
	char s[10001];
	char y[10001];
}mail;

int cmp(const void*a,const void*b)
{
	mail *p,*q;
	p=(mail*)a;q=(mail*)b;
	if(strcmp(p->y,q->y)>0) return 1;
	else if(strcmp(p->y,q->y)<0) return -1;
	else{
		if(strcmp(p->s,q->s)>0) return -1;
		else return 1;
	}
}

int main()
{
	int n,i;
	scanf("%d",&n);
	mail ml[400000];
	for(i=0;i<n;i++)
	{
		char a[1001];
		scanf("%s",a);
		int len=strlen(a),j=0,k=0;
		for(j=0;a[j]!='@';j++) ml[i].s[j]=a[j];
		for(j;j<len;j++) ml[i].y[k++]=a[j];
		memset(a,'\0',sizeof(a));
	}
	qsort(ml,n,sizeof(ml[0]),cmp);
	for(i=0;i<n;i++) printf("%s%s\n",ml[i].s,ml[i].y);
	return 0;
}