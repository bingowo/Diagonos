#include<stdio.h>
#include<stdlib.h>
struct data
{
	int d;
	int wei;
};
int area(int n,int a[],int b)
{
    int t=0;
    while(a[t]!=b&&t<=n)
    {
        t++;
    }
    return t;
}
int cmp1(const void *pa,const void *pb)
{
    int a,b;
    a=*((int *)pa);
    b=*((int *)pb);
    return a-b;
}
int cmp2(const void *pa,const void *pb)
{
	struct data a,b;
	a=*((struct data *)pa);
	b=*((struct data *)pb);
	return a.wei-b.wei;
}
int main()
{
    int n1,n2;
    scanf("%d",&n1);
    int a[n1];
    for(int i=0;i<n1;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&n2);
    int b[n2];
    int t=0;
    for(int i=0;i<n2;i++)
    {
        scanf("%d",&b[i]);
        if(area(n1,a,b[i])==n1+1)
        {
        	t++;
		}
    }
    if(t==n2)
    {
        qsort(b,n2,sizeof(int),cmp1);
        for(int i=0;i<n2-1;i++)
        {
            printf("%d ",b[i]);
        }
        printf("%d",b[n2-1]);
    }
    else
    {
        int c[t];
        struct data p[n2-t];
        int m=0;
        int s=0;
        for(int i=0;i<n2;i++)
        {
            if(area(n1,a,b[i])==n1+1)
            {
            	c[m]=b[i];
            	m++;
            }
            else
            {
            	p[s].wei=area(n1,a,b[i]);
            	p[s].d=b[i];
            	s++;
            }
        }
        qsort(p,n2-t,sizeof(p[0]),cmp2);
        qsort(c,t,sizeof(int),cmp1);
        for(int q=0;q<n2-t;q++)
        {
            printf("%d ",p[q].d);
        }
        for(int v=0;v<t;v++)
        {
            printf("%d ",c[v]);
        }
	}
    return 0;
}