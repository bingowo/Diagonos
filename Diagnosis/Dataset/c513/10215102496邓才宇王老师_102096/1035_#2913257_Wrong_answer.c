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
int cmp1(const void *p1,const void *p2)
{
    long long int* a=p1;
    long long int* b=p2;
    return *b-*a;
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    CS a[1001];
    long long int b[1001];
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&a[i].R,&a[i].H);
    }
    qsort(a,n,sizeof(CS),cmp);
    long long int an[1001]={0};
    for(int j=0;j<n;j++)
    {
        int count=0;
        long long int ans=0;
        ans=ans+a[j].R*a[j].R+2*a[j].H*a[j].R;
        for(int k=0;k<n;k++)
        {
            if(a[k].R<=a[j].R&&a[k].H!=a[j].H)
            {
                ans=ans+2*a[k].H*a[k].R;
                count++;
            }
            if(count==m-1)
            {
                an[j]=ans;
                break;
            }
        }
    }
    qsort(an,n,sizeof(long long int),cmp1);
    printf("%lld",an[0]);
}
