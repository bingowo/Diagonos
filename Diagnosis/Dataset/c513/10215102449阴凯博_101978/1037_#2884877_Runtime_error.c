#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
    long long* arr=(long long*)malloc(n*sizeof(long long));
    for (i=0;i<n;i++)
        scanf("%lld",&arr[i]);
    qsort(arr,n,sizeof(long long),cmp);
    GAP* arr2=(GAP*)calloc((n-m+1),sizeof(GAP));
    if (m==1) printf("0\n");
    else
    {
        for (i=m-1;i<n;i++)
        {
            arr2[i].res=arr[i]-arr[i-1];
            arr2[i].order=i;
        }
        qsort(arr2,n-m+1,sizeof(GAP),cmp2);
        int o=arr2[0].order;
        long long result=0; result+=arr2[0].res;
        if (m==2) printf("%lld\n",result);
        else
        {
            for (i=0;i<m;i++)
                result+=arr[o]-arr[o-i-1];
            printf("%lld\n",result);
        }
    }
    free(arr); free(arr2);
    return 0;
}
