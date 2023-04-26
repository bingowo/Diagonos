#include<stdio.h>
#include<stdlib.h>
struct data
{
    int r;
    int h;
};
int cmp1(const void *pa,const void *pb)
{
    struct data a,b;
    a=*((struct data *)pa);
    b=*((struct data *)pb);
    return b.r-a.r;
}
int cmp2(const void *pa,const void *pb)
{
    int a,b;
    a=*((int *)pa);
    b=*((int *)pb);
    return b-a;
}
int main()
{
    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    struct data circle[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&circle[i].r);
        scanf("%d",&circle[i].h);
    }
    qsort(circle,n,sizeof(circle[0]),cmp1);
    int d[n-m+1];
    for(int q=0;q<n-m+1;q++)
    {
        d[q]=0;
    }
    for(int j=0;j<n-m+1;j++)
    {
        for(int k=0;k<m;k++)
        {
            d[j]=d[j]+2*circle[j+k].r*circle[j+k].h;
        }
        d[j]=d[j]+circle[j].r*circle[j].r;
    }
    qsort(d,n-m+1,sizeof(int),cmp2);
    printf("%d",d[0]);
    return 0;
}