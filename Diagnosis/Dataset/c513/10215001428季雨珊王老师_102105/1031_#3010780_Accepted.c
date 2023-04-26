#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
int cmp(const void *a,const void *b){
    return (*(int *)a-*(int *)b);
}
int main(){
    int T;
    scanf("%d",&T);//问题数
    for(int t=0;t<T;t++){
        int n;
        scanf("%d",&n);//向量维数
        int *a,*b;
        a=(int *)malloc(sizeof(int)*n);
        b=(int *)malloc(sizeof(int)*n);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i++){
            scanf("%d",&b[i]);
        }
        qsort(a,n,sizeof(a[0]),cmp);
        qsort(b,n,sizeof(b[0]),cmp);
        int result=0;
        for(int i=0;i<n;i++){
            result+=a[i]*b[n-i-1];
        }
        printf("case #%d:\n%d\n",t,result);
    }
    return 0;
}
