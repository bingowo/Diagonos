#include <stdio.h>
#include <stdlib.h>
int cmp(const void *p1,const void *p2){
    long long int *a= (long long int *)p1;
    long long int *b= (long long int *)p2;
    return (*a)>(*b)?-1:1;
}
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    long long int a[n];
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    qsort(a,n, sizeof(long long int ),cmp);
    long long int b[n-m+1];
    for(int j=0;j<n-m+1;j++){
        b[j] =0;
        for(int p=0;p<m;p++){
            b[j] = b[j]+a[0]-a[j+p];
        }
    }
    qsort(b,n-m+1, sizeof(long long int),cmp);
    printf("%lld",b[n-m+1]);
    return 0;
}
