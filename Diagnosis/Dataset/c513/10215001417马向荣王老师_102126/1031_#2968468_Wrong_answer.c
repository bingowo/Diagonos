#include<stdio.h>
#include<stdlib.h>
int cmp1(const void *a,const void *b)
{
    int *p1=(int *)a;
    int *p2=(int *)b;
    return *p1-*p2;
}
int cmp2(const void *a,const void *b)
{
    int *p1=(int *)a;
    int *p2=(int *)b;
    return *p1-*p2;
}
int main()
{
    int t;
    scanf("%d\n",&t);
    for(int i=0;i<t;i++)
    {
        int n=0;
        scanf("%d\n",&n);
        int a[1000],b[1000];
        for(int j=0;j<n;j++)
        {
            scanf("%d ",&a[j]);
        }
        for(int j=0;j<n;j++)
        {
            scanf("%d ",&b[j]);
        }
        qsort(a,n,sizeof(int),cmp1);
        qsort(b,n,sizeof(int),cmp2);
        int sum=0;
        for(int j=0;j<n;j++)
        {
            sum=sum+a[j]+b[j];
        }
        printf("case #%d:\n%d\n",i,sum);
    }
    return 0;
}