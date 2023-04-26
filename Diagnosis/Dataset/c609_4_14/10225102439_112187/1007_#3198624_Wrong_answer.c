#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    long long int x,y;
    x=*((long long int*)a);
    y=*((long long int*)b);
    unsigned long long m,n,cnt1,cnt2;
    if (x<0) m=x+18446744073709551616;
    else m=x;
    if (y<0) n=y+18446744073709551616;
    else n=y;
    while (m!=0)
    {
        if (m%2==1) cnt1++;
        m/=2;
    }
    while (n!=0)
    {
        if (n%2==1) cnt2++;
        n/=2;
    }
    if (cnt1>cnt2) return -1;
    else if (cnt1==cnt2)
    {
        if (x<y) return -1;
        else return 1;
    }
    else return 1;
}

int main()
{
    int qn,n,j=0;
    scanf("%d",&qn);
    while ((scanf("%d",&n))!=-1)
    {
        long long int a[n];
        for (int i=0;i<n;i++) scanf("%lld",a+i);
        qsort(a,n,sizeof(long long int),cmp);
        printf("case #%d:\n",j);
        for (int t=0;t<n;t++)
            printf("%lld ",a[t]);
        printf("\n");
        j++;
    }
    return 0;
}
