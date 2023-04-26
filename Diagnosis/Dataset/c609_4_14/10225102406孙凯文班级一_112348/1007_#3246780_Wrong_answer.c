#include<stdio.h>
#include<stdlib.h>

int cmp(const void*A,const void*B)
{
    int a=*(long long int *)A;
    int b=*(long long int *)B;
    unsigned long long int sa=0,sb=0,aa=(long long unsigned)a,bb=(long long unsigned)b;
    while(aa!=0)
    {
        if(aa&1) sa++;
        aa=aa>>1;
    }
    while(bb!=0)
    {
        if(bb&1) sb++;
        bb=bb>>1;
    }
    if(sa>sb) return -1;
    else if(sa<sb) return 1;
    else if(a<b) return -1;
    else return 1;
}
int main()
{
    int t,n;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d",&n);
        long long a[n],b;
        for(int j=0;j<n;j++)
        {
            scanf("%lld",&b);
            a[j]=b;
        }
        qsort(a,n,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        for(int q=0;q<n;q++) {printf("%lld",a[q]);if(q!=n-1) printf(" ");}
        printf("\n");
    }
    return 0;
}