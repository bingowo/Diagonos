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
    long long int b=0;
    for(int i=1;i<m;i++){
        b = b +a[0]-a[i];
    }
    for(int j=1;j<n-m+1;j++){
        long long int b1 = (m-1)*a[j];
        for(int p=1;p<m;p++){
            b1 = b1-a[j+p];
        }
        if(b1<b){
            b = b1;
        }
    }
    printf("%lld",b);
    return 0;
}
