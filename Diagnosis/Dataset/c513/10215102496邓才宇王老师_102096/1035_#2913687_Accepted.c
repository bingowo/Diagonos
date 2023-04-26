#include <stdio.h>
#include <stdlib.h>
typedef struct{
    long long int R;
    long long int H;
}CS;
int cmp(const void *p1,const void *p2)
{
    CS* a=p1;
    CS* b=p2;
    long long int q=(a->H)*(a->R);
    long long int w=(b->H)*(b->R);
    if(q>w) return -1;
    else if(q<w) return 1;
    else return 0;
}
int cmp1(const void *p1,const void *p2)
{
    long long int* a=p1;
    long long int* b=p2;
    if(*a>*b) return -1;
    else if(*a<*b) return 1;
    else return 0;
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    CS a[1001];
    long long int b[1001];
    for(int i=0;i<n;i++)
    {
        scanf("%lld %lld",&a[i].R,&a[i].H);
    }
    qsort(a,n,sizeof(CS),cmp);
    long long int an[1001];
    for(int q=0;q<n;q++) an[q]=0;
    for(int j=0;j<n;j++)
    {
        int count=0;
        long long int ans=0;
        ans=ans+2*a[j].H*a[j].R+a[j].R*a[j].R;
        for(int k=0;k<n;k++)
        {
            if(count==m-1)
            {
                an[j]=ans;
                break;
            }
            if(a[k].R<=a[j].R&&k!=j)
            {
                ans=ans+2*a[k].H*a[k].R;
                count++;
            }
        }
    }
    qsort(an,n,sizeof(long long int),cmp1);
    printf("%lld",an[0]);
}
