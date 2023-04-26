#include<stdio.h>
#include<stdlib.h>
int cmp1(const void *x,const void*y){//升序
    return *(int*)x-*(int*)y;
}
int cmp2(const void *x,const void*y){//降序
    return *(int *)y-*(int *)x;
}
int main(){
    int t;scanf("%d",&t);getchar();int idx=0;
    while(t--){
        int n;scanf("%d",&n);getchar();
        int *a=(int *)malloc(sizeof(int)*n);
        int *b=(int *)malloc(sizeof(int)*n);
        for(int i=0;i<n;i++){
            scanf("%d",(a+i));
        }getchar();qsort(a,n,sizeof(int ),cmp1);
        for(int i=0;i<n;i++){
            scanf("%d",(b+i));
        }getchar();qsort(b,n,sizeof(int),cmp2);
        long long int ret=0;//一定要记得初始化
        for(int i=0;i<n;i++){
            ret+=a[i]*b[i];
        }
        printf("case #%d:\n%lld\n",idx++,ret);
    }
}