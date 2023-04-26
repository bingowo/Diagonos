#include <stdio.h>
#include <stdlib.h>
int cmp(const void *p1,const void *p2){
    return (int *)p1-(int *)p2;
}
int main() {
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(int),cmp);
    long long int sum = 0;
    for(int j =0;j<n;j = j+2){
        sum = sum + a[j+1] -a[j];
    }
    printf("%lld",sum);
    return 0;
}
