#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    int order;
    long long res1;
    long long res2;
} GAP;

int cmp(const void* a,const void* b)
{
    long long* pa=(long long*)a; long long* pb=(long long*)b;
    return *pa>*pb?-1:1;
}

int cmp2(const void* a,const void* b)
{
    GAP* pa=(GAP*)a; GAP* pb=(GAP*)b;
    if (pa->res1>pb->res1) return 1;
    if (pa->res1<pb->res1) return -1;
    if (pa->res1==pb->res1)
    {
        return pa->res1>pb->res1?1:-1;
    }

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
        for (i=0;i<n-m+1;i++)
        {
        arr2[i].order=i;
        arr2[i].res1=arr[i]-arr[i+m-1];
        arr2[i].res2=arr[i+m-2]-arr[i+m-1];
        }
        qsort(arr2,n-m+1,sizeof(GAP),cmp2);
        long long result=0;
        int o=arr2[0].order;
        for (i=1;i<m;i++)
            result+=arr[o]-arr[o+i];

        printf("%lld\n",result);
        free(arr); free(arr2);
    }

    return 0;
}
