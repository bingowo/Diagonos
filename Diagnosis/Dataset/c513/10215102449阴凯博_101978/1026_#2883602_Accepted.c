#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    int a;
    int b;
    int r;
} POINT;


int cmp(const void* a,const void* b)
{
    int* pa=(int*)a; int* pb=(int*)b;
    return *pa>*pb?-1:1;
}

int main()
{
    int n,i,j=0,m=0;
    scanf("%d",&n);
    int* arr=(int*)malloc(n*sizeof(int));
    POINT* S=(POINT*)malloc(n/2*sizeof(POINT));
    for (i=0;i<n;i++)
        scanf("%d",&arr[i]);
    qsort(arr,n,sizeof(int),cmp);
    for (i=0;i<n;i+=2)
    {
        S[j++].a=arr[i];
        if (j==n/2) break;
    }

    j=0;
    for (i=1;i<n;i+=2)
    {
        S[j++].b=arr[i];
        if (j==n/2) break;
    }
    for (i=0;i<n/2;i++)
        S[i].r=S[i].a-S[i].b;
    for (i=0;i<n/2;i++)
        m+=S[i].r;
    printf("%d\n",m);
    free(arr); free(S);
    return 0;
}
