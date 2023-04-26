#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b){
    return *(int*)a>*(int*)b;
}

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    int sum=0;
    for(int i=0;i<(n/2);i++){
        sum=sum+a[2*i+1]-a[2*i];
    }
    printf("%d",sum);
    return 0;
}