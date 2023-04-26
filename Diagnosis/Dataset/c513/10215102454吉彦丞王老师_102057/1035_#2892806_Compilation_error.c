#include<stdio.h>
#include<stdlib.h>
struct data
{
    int r;
    int h;
};
int cmp(const void *pa,const void *pb)
{
    struct data a,b;
    a=*((struct data *)pa);
    b=*((struct data *)pb);
    return b.r-a.r;
}
int cmp1(const void *pa,const void *pb)
{
    int a,b;
    a=*((int *)pa);
    b=*((int *)pb);
    return b-a;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int r[n];
    int h[n];
    int s[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&circle[i].r);
        scanf("%d%d",&circle[i].h);
    }
    qsort(circle,n,sizeof(circle[0]),cmp);
    int deep[n];
    for(int j=0;j<n-1;j++)
    {
        deep[j]=circle[j+1].r*circle[j+1].r-circle[j].r*circle[j].r+2*circle[j+1].r*circle[j+1].h;
    }
    qsort(deep,n-1,sizeof(int),cmp1);
    deep[n]=
    int result=0;
    for(int k=0;k<m;k++)
    {
        result=result+deep[k];
    }
}