#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    long long int x,y,m,n;
    x=*((long long int*)a);
    y=*((long long int*)b);
    m=x;
    n=y;
    int cnt1=0,cnt2=0;
    while (x)
    {
        x&=(x-1);
        cnt1++;
    }
    while (y)
    {
        y&=(y-1);
        cnt2++;
    }
    if (cnt1<cnt2) return 1;
    else if (cnt1==cnt2)
    {
        if (m<n) return -1;
        else return 1;
    }
    else return -1;

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
