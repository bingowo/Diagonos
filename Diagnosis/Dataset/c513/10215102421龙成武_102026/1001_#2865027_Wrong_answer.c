#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int changeit(int N,int R)
{
    int result=0;
    while(N>R)
    {
        result=result*10+N%R;
        N=N/R;
    }
    result=result*10+N;
    return result;
}

int main()
{
    int T;
    scanf("%d",&T);
    int *a;
    a=(int*)malloc(2*T*sizeof(int));
    for(int i=0;i<2*T;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<T;i++)
    {
        int j=2*i;
        printf("%d\n",changeit(a[j],a[j+1]));
    }
    free(a);
    return 0;
}
