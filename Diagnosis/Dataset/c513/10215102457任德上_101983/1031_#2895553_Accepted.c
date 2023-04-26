#include<stdio.h>
#include<malloc.h>
int cmp(const void *a,const void *b){
    int *a1,*a2;
    a1=(int*)a;
    a2=(int*)b;
    return *a1-*a2;
}
int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int n,*a,*b,key=0;
        scanf("%d",&n);
        a=(int*)malloc(n*sizeof(int));
        b=(int*)malloc(n*sizeof(int));
        for(int m=0;m<n;m++)scanf("%d",&a[m]);
        for(int m=0;m<n;m++)scanf("%d",&b[m]);
        qsort(a,n,sizeof(int),cmp);
        qsort(b,n,sizeof(int),cmp);
        for(int m=0;m<n;m++)key+=a[m]*b[n-1-m];
        printf("case #%d:\n%d\n",i,key);
    }
    return 0;
}