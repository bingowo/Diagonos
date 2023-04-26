#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define N 101

int cmp1(const void *a,const void* b)
{
    int* pa=(int*)a;
    int* pb=(int*)b;
    return ((*pa)>(*pb))?1:-1;
}

int cmp2(const void *a,const void* b)
{
    int* pa=(int*)a;
    int* pb=(int*)b;
    return ((*pa)>(*pb))?-1:1;
}


int main()
{
    char c;
    scanf("%c",&c);
    int i=0,*a,n;
    a=(int*)calloc(N,sizeof(int));
    while (scanf("%d",&a[i++])!=EOF) ;
    if (c=='A') qsort(a,i-1,sizeof(int),cmp1);
    else qsort(a,i-1,sizeof(int),cmp2);
    if (i-1==1)
        printf("%d\n",a[0]);
    for (int j=0;j<i-2;j++)
    {

        if (j==i-3)
        {
            if (a[j]!=a[j+1])
                printf("%d %d\n",a[j],a[j+1]);
            if (a[j]==a[j+1])
                printf("%d\n",a[j]);
        }

        else if (a[j]!=a[j+1])
        {
            printf("%d ",a[j]);
        }
    }

    return 0;
}