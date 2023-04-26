#include<stdio.h>
#include<stdlib.h>
int arr1[100000],arr2[100000];
int cmp1(const void * a,const void * b)
{
    int *c=(int *)a;
    int *d=(int *)b;
    if(*c!=*d) return *c-*d;
    else return *d-*c;
}
int cmp2(const void * a,const void * b)
{
    int *c=(int *)a;
    int *d=(int *)b;
    if(*c!=*d) return *d-*c;
    else return *c-*d;
}
int main()
{
    int i,n;
    long long sum;
    int t;
    scanf("%d",&t);
    for(int m=0;m<t;m++)
    {       
        scanf("%d",&n);
        sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr1[i]);
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr2[i]);
        }
        qsort(arr1,n,sizeof(int),cmp1);
        qsort(arr2,n,sizeof(int),cmp2);
        for(i=0;i<n;i++)
        {
            sum=sum+(long long)arr1[i]*arr2[i];
        }
        printf("case #%d:\n",m);
        printf("%lld\n",sum);
    }
    return 0;
}  