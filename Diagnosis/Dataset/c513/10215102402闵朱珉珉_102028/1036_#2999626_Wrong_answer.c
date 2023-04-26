#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct{int x;int y;} point;
int cmp(const void *a,const void *b)
{
    point *a1=(point*)a,*b1=(point*)b;
    int n1=abs(a1->x)+abs(a1->y),n2=abs(b1->x)+abs(b1->y);
    if (n1!=n2) return n2-n1;
    else if(a1->x!=b1->x) return a1->x-b1->x;
    else return a1->y-b1->y;
}
int solve(point a)
{
    int n=abs(a.x)+abs(a.y);
    if (n==0) return 0;
    if (n%2==0) return -1;
    double x=log(n+1)/log(2);
    for (int k=0;k<43;k++)
        if (k-1<x&&x<=k) return k;
    return 1;
}
int main ()
{
    int n;
    scanf ("%d",&n);
    point in[101];
    for (int q=0;q<n;q++)
    {
        scanf("%d%d",&in[q].x,&in[q].y);
    }
    qsort(in,n,sizeof(in[0]),cmp);
    int result=abs(in[0].x-in[1].x)+abs(in[0].y-in[1].y);
    int sum=0,t=0,i=0;
    while (i<n)
    {
        t=solve(in[i]);
        if (t!=-1) sum+=t;
        else break;
        i++;
    }
    printf("%d\n%d",result,sum);
    return 0;
}
