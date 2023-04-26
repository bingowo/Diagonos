#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
typedef struct{
	float a;
	char b;
}qwq;
int cmp(const void*a,const void*b)
{
	qwq*p1=(qwq*)a;qwq*p2=(qwq*)b;
	if(p1->a>p2->a) return -1;
	else if(p1->a<p2->a) return 1;
	else
	{
		int i1=0,i2=0;
		char c1=p1->b,c2=p2->b;
		if(c1>='A'&&c1<='Z') c1+=32,i1=1;
		if(c2>='A'&&c2<='Z') c2+=32,i2=1; 
		if(c1>c2) return 1;
		else if(c1<c2) return -1;
		else
		{
			if(i1==0&&i2==1) return -1;
			else if(i1==1&&i2==0) return 1;
		}
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		float A[30];char B[100];
		for(int j=0;j<26;j++) scanf("%f",&A[j]);
		scanf("%s",B);
		int l=strlen(B);
		qwq *p=(qwq*)malloc(l*sizeof(qwq));
		for(int j=0;j<l;j++) p[j].b=B[j];
		for(int j=0;j<l;j++)
		{
			if(p[j].b>='A'&&p[j].b<='Z') p[j].a=A[p[j].b-'A'];
			else if(p[j].b>='a'&&p[j].b<='z') p[j].a=A[p[j].b-'a'];
		}
		qsort(p,l,sizeof(p[0]),cmp);
		printf("case #%d:\n",i);
		for(int j=0;j<l;j++)
		{
			printf("%c",p[j].b);
		}printf("\n");
		free(p);	
	}
	
}