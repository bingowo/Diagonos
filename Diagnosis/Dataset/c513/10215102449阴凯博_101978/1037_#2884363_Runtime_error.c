#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int cmp(const void* a,const void* b)
{
    long long* pa=(long long*)a; long long* pb=(long long*)b;
    return *pa>*pb?1:-1;

}

int main()
{
    int n,m,i,j=0;
    scanf("%d %d",&n,&m);
    long long* arr=(long long*)malloc(n*sizeof(int));
    for (i=0;i<n;i++)
        scanf("%lld",&arr[i]);
    qsort(arr,n,sizeof(long long),cmp);
    long long result=0; i=0;
    for (j=m-2;j>=0;j--)
    {
        result+=(arr[m-1]-arr[j]);
    }
    printf("%lld\n",result);
    return 0;
}
