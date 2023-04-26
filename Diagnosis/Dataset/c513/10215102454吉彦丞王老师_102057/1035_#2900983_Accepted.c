#include<stdio.h>
#include<stdlib.h>
struct data
{
    long long int r;
    long long int h;
};
int cmp1(const void *pa,const void *pb)
{
    struct data a,b;
    a=*((struct data *)pa);
    b=*((struct data *)pb);
    if(b.r<a.r)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}
int cmp2(const void *pa,const void *pb)
{
    long long int a,b;
    a=*((long long int *)pa);
    b=*((long long int *)pb);
    if(b-a<0)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}
int main()
{
    long long int n,m;
    scanf("%lld",&n);
    scanf("%lld",&m);
    struct data circle[n];
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&circle[i].r);
        scanf("%lld",&circle[i].h);
    }
    qsort(circle,n,sizeof(circle[0]),cmp1);
    long long int d[n-m+1];
    for(int q=0;q<n-m+1;q++)
    {
        d[q]=circle[q].r*circle[q].r+2*circle[q].r*circle[q].h;
    }
    for(int j=0;j<n-m+1;j++)
    {
        long long int link[n-1-j];
        for(int t=0;t<n-1-j;t++)
        {
            link[t]=2*circle[t+j+1].r*circle[t+j+1].h;
        }
        qsort(link,n-1-j,sizeof(long long int),cmp2);
        for(int o=0;o<m-1;o++)
        {
            d[j]=d[j]+link[o];
        }
    }
    qsort(d,n-m+1,sizeof(long long int),cmp2);
    printf("%lld",d[0]);
    return 0;
}