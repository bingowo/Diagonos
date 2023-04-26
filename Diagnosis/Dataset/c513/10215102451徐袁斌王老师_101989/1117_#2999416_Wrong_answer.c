#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct pos{
    int a;
    int b;
    int c;
};
int cmp(const void *a,const void *b)
{
    struct pos*A=(struct pos*)a;
    struct pos*B=(struct pos*)b;
    if(A->c!=B->c)
    {
    	return (A->c)-(B->c);
	}
	else if(A->a!=B->a)
	{
		return (A->a)-(B->a);
	}
	else return (A->b)-(B->b);
}
struct pos x[1000000];
int main()
{
    int x0,y0,t;
    scanf("%d%d",&x0,&y0);
    scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
	   	scanf("%d%d",&x[i].a,&x[i].b);
	   	int a=abs(x[i].a-x0),b=abs(x[i].b-y0);
	   	if(a>b) x[i].c=a;
	   	else x[i].c=b;
	}
	qsort(x,t,sizeof(x[0]),cmp);
	printf("%d\n",x[0].c);
	printf("%d %d",x[0].a,x[0].b);
}