#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int R;
    int H;
}CS;
int cmp(const void *p1,const void *p2)
{
    CS* a=p1;
    CS* b=p2;
    long long int q=(a->H)*(a->R);
    long long int w=(b->H)*(b->R);
    return w-q;
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    CS a[1001];
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&a[i].R,&a[i].H);
    }
    qsort(a,n,sizeof(CS),cmp);
    long long int ans=0;
    int max=0;
    for(int j=0;j<m;j++)
    {
        ans=ans+2*(a[j].H)*(a[j].R);
    }
    for(int k=0;k<n;k++)
    {
        if(max<a[k].R) max=a[k].R;
    }
    ans=ans+max*max;
    printf("%lld",ans);
}
