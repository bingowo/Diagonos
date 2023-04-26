#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct{
	char *s;
	char *y;
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
	mail *ml;
	ml=(mail*)malloc(sizeof(mail)*n);
	for(i=0;i<n;i++)
	{
		char a[10001];
		scanf("%s",a);
		int len=strlen(a),j=0,k=0;
		ml[i].s=(char*)malloc(len+1);
		ml[i].y=(char*)malloc(len+1);
		for(j=0;a[j]!='@';j++) ml[i].s[j]=a[j];
		for(j;j<len;j++) ml[i].y[k++]=a[j];
	
	}
	qsort(ml,n,sizeof(ml[0]),cmp);
	for(i=0;i<n;i++) printf("%s%s\n",ml[i].s,ml[i].y);
	for(i=0;i<n;i++)
	{
		free(ml[i].s);
		free(ml[i].y);
	}
	
	free(ml);
	
	return 0;
}