#include<stdio.h>
#include<stdlib.h>

struct nub{
long long size;
int one;
};

int cmp(const void*A,const void*B)
{
    nub *aa=(struct*)A;
    nub *bb=(struct*)B;
    if(aa.one>bb.one) return -1;
    else if(aa.one<bb.one) return 1;
    else if(aa.size>bb.size) return -1;
    else return 1;
}
int main()
{
    int t,n;
    //long long aa;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d",&n);
        struct nub a[n];
        for(int j=0;j<n;j++)
        {
            scanf("%lld",&a[j].size);
            int sum=0;
            int b=a[j].size;
            while(b!=0)
            {
                if(b&1) sum++;
                b>>1;
            }
            a[j].one=sum;
        }
    }
    qsort(a,n,sizeof(a[0]),cmp);
    for(int i=0;i<n;i++) printf("%d",a[i].size);
    return 0;
}