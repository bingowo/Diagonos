#include <stdio.h>
#include <stdlib.h>

int cmpA(const void *a, const void *b){
    return *(int *)a-*(int *)b;
}

int cmpD(const void *a, const void *b){
    return *(int *)b-*(int *)a;
}

int main() {
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int n;
        scanf("%d",&n);
        int *a=(int *) malloc(sizeof (int)*n);
        int *b=(int *) malloc(sizeof (int)*n);
        for(int j=0;j<n;j++)
            scanf("%d",&a[j]);
        for(int j=0;j<n;j++)
            scanf("%d",&b[j]);
        qsort(a,n,sizeof (int),cmpA);
        qsort(b,n,sizeof (int),cmpD);
        long long sum=0;
        for(int j=0;j<n;j++)
            sum+=a[j]*b[j];
        printf("case #%d:\n");
        printf("%lld",sum);
    }
    return 0;
}
