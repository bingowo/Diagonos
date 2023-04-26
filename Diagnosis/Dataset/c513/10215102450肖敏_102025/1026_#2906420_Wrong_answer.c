#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    int L[n],i,sum = 0;
    for(i= 0;i < n;i ++)
        scanf("%d",&L[i]);
    int cmp(const void *a,const void * b)
    {
        int *a1 = (int*)a,*b1 = (int*)b;
        return a1 - b1;
    }
    qsort(L,n,sizeof(L[0]),cmp);

    for(i = 0;i < n;i += 2)
    {
        if(L[i] < 0 && L[i +1] <0)
            sum += L[i] - L[i+1];
        else
            sum += L[i +1] -L[i];
    }
    printf("%d\n",sum);
    return 0;
}
