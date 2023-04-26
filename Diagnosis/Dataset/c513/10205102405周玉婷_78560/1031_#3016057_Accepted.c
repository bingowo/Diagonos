#include <stdio.h>
#include <stdlib.h>
int arr1[1000], arr2[1000];

int cmp1(const void*pa, const void *pb)
{
    int a=*(int *)pa;
    int b=*(int *)pb;
    if(a != b) return a-b;//升序
    else return -1;
}

int cmp2(const void*pa, const void *pb)
{
    int a=*(int *)pa;
    int b=*(int *)pb;
    if(a != b) return b-a;//降序
    else return -1;
}


int main()
{
    int t;
    scanf("%d",&t);
    for(int j = 0; j < t; j++)
    {
        int n;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&arr1[i]);
        }
        for(int i=0; i<n; i++)
        {
            scanf("%d",&arr2[i]);
        }
        qsort(arr1,n,sizeof(int),cmp1);
        qsort(arr2,n,sizeof(int),cmp2);
        long long sum=0;
        for(int i=0; i<n; i++)
        {
            sum = sum + (long long)arr1[i]*arr2[i];
        }
        printf("case #%d:\n",j);
        printf("%lld\n",sum);
    }
    return 0;
}