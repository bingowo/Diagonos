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
    long long int ret = b;
    for(int j=1;j<n-m+1;j++){
        b = b - ((m-1)*a[j-1])+   (m*a[j]) - a[j-m+1];
        if(b<ret){
            ret = b;
        }
    }
    printf("%lld",ret);
    return 0;
}
