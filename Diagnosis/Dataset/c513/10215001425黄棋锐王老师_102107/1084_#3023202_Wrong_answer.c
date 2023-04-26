#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define  MAXN  200
typedef struct
{
	int cnt;
	int v[MAXN];
}BIG;

void BIGMUL2(BIG*a)
{  int carry=0,i=0;
	for(i=0;i<=a->cnt;i++)
	{  	a->v[i]*=2;
		a->v[i]+=carry;
		a->v[i]%=10;
		carry=a->v[i]/10;
	}
	if(a->v[a->cnt]>0) a->cnt++;
}

int main() 
{   int k,T;
	scanf("%d\n",&T);
	for(k=0;k<T;k++)
	{   int N;
		scanf("%d",&N);
		BIG a;
		a.cnt=1;
		int i;
		for(i=1;i<200;i++) a.v[i]=0;
		a.v[0]=1;
		printf("case #%d:\n",k);
		for(i=0;i<N;i++) BIGMUL2(&a);
		for(i=a.cnt-1;i>=0;i--) printf("%d",a.v[i]);
		printf("\n");
	}
	return 0;
}