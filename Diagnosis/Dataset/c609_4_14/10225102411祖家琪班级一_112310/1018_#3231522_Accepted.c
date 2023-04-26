#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int n,cnt = 0;
    long long res = 0;
    scanf("%d",&n);
    int *pit = (int *)malloc(4*n);
    int cmp(const void *,const void *);
    do{
        scanf("%d",&pit[cnt++]);
    }while(getchar() != '\n');
    qsort(pit,n,4,cmp);
    for(int i = 0;i<n-1;i += 2){
        res += (pit[i+1] -  pit[i]);
    }
    free(pit);
    printf("%lld",res);
    return 0;
}
int cmp(const void *a,const void *b)
{
    int *pa = (int *)a;
    int *pb = (int *)b;
    return *pa - *pb;
}
