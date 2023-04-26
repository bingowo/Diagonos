#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct
{
    int order;
    long long res;
} GAP;

int cmp(const void* a,const void* b)
{
    long long* pa=(long long*)a; long long* pb=(long long*)b;
    return *pa>*pb?1:-1;
}

int cmp2(const void* a,const void* b)
{
    GAP* pa=(GAP*)a; GAP* pb=(GAP*)b;

    return pa->res>pb->res?1:-1;

}

int main()
{
    int n,m,i,j=0;
    scanf("%d %d",&n,&m);
    if (m==1) printf("0\n");
    else
    {
        long long* arr=(long long*)malloc(n*sizeof(*arr));
        for (i=0;i<n;i++)
            scanf("%lld",&arr[i]);
        qsort(arr,n,sizeof(long long),cmp);
        GAP *arr2=(GAP*)malloc((n-m+1)*sizeof(GAP));
        long long sum;
        arr2[0].res=0;
        for (j=m-1;j>=0;j--)
        {
            arr2[0].res+=arr[m-1]-arr[j];
            sum+=arr[j];
        }
        arr2[0].order=0;
        for (i=1;i<n-m+1;i++)
        {
            arr2[i].order=i;
            arr2[i].res=sum-arr[i+m-1];
        }
        qsort(arr2,n-m+1,sizeof(GAP),cmp2);
        printf("%lld\n",arr2[0].res);


    }

    return 0;
}
