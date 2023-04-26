#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct{long long x;long long y;} point;
int cmp(const void *a,const void *b)
{
    point *a1=(point*)a,*b1=(point*)b;
    long long n1=abs(a1->x)+abs(a1->y),n2=abs(b1->x)+abs(b1->y);
    if (n1>n2) return -1;
    else if(n1<n2) return 1;
    else if(a1->x>b1->x) return 1;
    else if(a1->x<b1->x) return -1;
    else if(a1->y>b1->y) return 1;
    else return -1;
}
int solve(point a,point b)
{
    long long n=abs(a.x-b.x)+abs(a.y-b.y);
    if (n==0) return 0;
    if (n%2==0) return -1;
    double x=log(n+1)/log(2);
    for (int k=0;k<200;k++)
        if (k-1<x&&x<=k) return k;
}
int main ()
{
    int n;
    scanf ("%d",&n);
    point in[101];
    for (int q=0;q<n;q++)
    {
        scanf("%lld%lld",&in[q].x,&in[q].y);
    }
    qsort(in,n,sizeof(in[0]),cmp);
    long long result=abs(in[0].x-in[1].x)+abs(in[0].y-in[1].y);
    long long sum=0,t=0,i=0;
    while (i<n-1)
    {
        t=solve(in[i],in[i+1]);
        if (t!=-1) sum+=t;
        else break;
        i++;
    }
    printf("%lld\n%lld",result,sum);
    return 0;
}
