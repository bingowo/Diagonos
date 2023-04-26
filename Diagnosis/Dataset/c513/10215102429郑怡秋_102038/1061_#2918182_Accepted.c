#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>
typedef struct{
	char s[30];
	long long ans;
}qwq;
long long po(int a,int b)
{
	long long x=1;
	for(int i=0;i<b;i++) x*=a;
	return x;
}
long long rev(int B[],int l)
{
	int max=0;
	for(int i=0;i<l;i++)
	{
		max=(max<B[i]?B[i]:max);
	}
	max+=1;
	long long res=0;
	for(int j=l-1;j>=0;j--)
	{
		res+=B[j]*po(max,l-1-j);
	}
	return res;
}
int cmp(const void *a,const void *b)
{
	qwq*p1=(qwq*)a;qwq*p2=(qwq*)b;
	if(p1->ans-p2->ans>0) return 1;
	else if(p1->ans-p2->ans<0) return -1;
	else
	{
		return strcmp(p1->s,p2->s);
	}
}

int main()
{
	int N;
	scanf("%d",&N);
	qwq*p=(qwq*)malloc(N*sizeof(qwq));
	for(int i=0;i<N;i++)
	{
		int A[130];
		for(int h=0;h<130;h++) A[h]=-1;
		scanf("%s",p[i].s);
		int l=strlen(p[i].s);
		char *q=p[i].s;
		A[*q]=1;
		int digit=0;
		while(*++q)
		{
			if(A[*q]==-1)
			{
				A[*q]=digit;digit=digit?digit+1:2;
			}
		}
		int B[20];
		for(int k=0;k<l;k++)
		{
			B[k]=A[p[i].s[k]];
		}
		p[i].ans=rev(B,l);//printf("%d\n",p[i].ans);
	}
	qsort(p,N,sizeof(p[0]),cmp);
	for(int q=0;q<N;q++) printf("%s\n",p[q].s);
	free(p);
	return 0;
	
 } 