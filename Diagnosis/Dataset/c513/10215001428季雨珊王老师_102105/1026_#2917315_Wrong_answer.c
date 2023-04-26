#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int cmp(const void *a,const void *b){
    int *aa=(int *)a;
    int *bb=(int *)b;
    return (a-b);
}
int main(){
    int n;//n个点
    scanf("%d",&n);
    long long int *a;
    a=(long long int *)malloc(sizeof(long long int)*n);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    long long int result=0;
    for(int i=0;i+1<n;){
        result+=(a[i+1]-a[i]);
        i+=2;
    }
    printf("%lld",result);
    return 0;
}
