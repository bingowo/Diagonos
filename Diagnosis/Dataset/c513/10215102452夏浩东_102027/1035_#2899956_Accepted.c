#include <stdio.h>
#include <stdlib.h>
struct M
{
    long long int R;
    long long int H;
};
int cmp(const void *a,const void *b)
{
    struct M* A=(struct M*)a;
    struct M* B=(struct M*)b;
    long long int S1=2*(A->H)*(A->R);
    long long int S2=2*(B->H)*(B->R);
    if(S1>=S2) return -1;
    else return 1;
}
int main()
{
    long long int n=0,m=0,max1=0,max2=0,res1=0,res2=0;
    int num=0;
    struct M L[1000];
    scanf("%lld %lld",&n,&m);
    for(int k=0;k<n;k++)
    {
        scanf("%lld %lld",&L[k].R,&L[k].H);
    }
    qsort(L,n,sizeof(struct M),cmp);
    for(int k=0;k<m;k++)
    {
        if(L[k].R*L[k].R>max1)
        {
            max1=L[k].R*L[k].R;
            num=k;
        }
    }
    if(num!=m-1)
    {
        for(int k=m;k<n;k++)
        {
            if(L[k].R>L[num].R && (L[k].R*L[k].R+2*L[k].R*L[k].H)>max2) max2=L[k].R*L[k].R+2*L[k].R*L[k].H;
        }
    }
    else
    {
        for(int k=m;k<n;k++)
        {
            if((L[k].R*L[k].R+2*L[k].R*L[k].H)>max2) max2=L[k].R*L[k].R+2*L[k].R*L[k].H;
        }
    }
    for(int k=0;k<m;k++)
    {
        res1+=2*L[k].R*L[k].H;
    }
    res2=res1-2*L[m-1].H*L[m-1].R+max2;
    res1=res1+max1;
    if(res1>res2) printf("%lld",res1);
    else printf("%lld",res2);
    return 0;
}