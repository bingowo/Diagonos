#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int cmp(const void *a,const void *b){
    return (*(int *)a-*(int *)b);
}
int main(){
    int n;//n个点
    scanf("%d",&n);
    int *a;
    a=(int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    int result=0;
    int i=0;
    while(i<n-1){
        result+=(a[i+1]-a[i]);
        i+=2;
    }
    printf("%d",result);
    return 0;
}
