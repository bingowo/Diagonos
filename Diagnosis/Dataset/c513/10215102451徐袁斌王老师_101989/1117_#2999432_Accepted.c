#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct pos{
    long long int a;
    long long int b;
    long long int c;
};
int cmp(const void *a,const void *b)
{
    struct pos*A=(struct pos*)a;
    struct pos*B=(struct pos*)b;
    if(A->c!=B->c)
    {
    	if(A->c>B->c) return 1;
    	else return -1;
	}
	else if(A->a!=B->a)
	{
		if(A->a>B->a) return 1;
		else return -1;
	}
	else 
	{
		if(A->b>B->b) return 1;
		else return -1;
	}
}
struct pos x[1000000];
int main()
{
    long long int x0,y0,t;
    scanf("%lld%lld",&x0,&y0);
    scanf("%lld",&t);
	for(int i=0;i<t;i++)
	{
	   	scanf("%lld%lld",&x[i].a,&x[i].b);
	   	long long int a=llabs(x[i].a-x0),b=llabs(x[i].b-y0);
	   	if(a>b) x[i].c=a;
	   	else x[i].c=b;
	}
	qsort(x,t,sizeof(x[0]),cmp);
	printf("%lld\n",x[0].c);
	printf("%lld %lld",x[0].a,x[0].b);
}