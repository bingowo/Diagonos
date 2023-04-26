#include<stdio.h>
#include<stdlib.h>
#define N 1001
int cmp1(const void* a,const void* b){   // 升序
    if(*(int*)a!=*(int*)b)return *(int*)a>*(int*)b?1:-1;
    return 0;
}
int cmp2(const void* a,const void* b){
    if(*(int*)a!=*(int*)b)return *(int*)a<*(int*)b?1:-1;
    return 0;
}
int main(){
    int T,a=0;
    scanf("%d",&T);
    while(a<T){
        int ret=0;
        int n;int veta[N]={0};int vetb[N]={0};
        scanf("%d",&n);
        for(int i=0;i<n;++i)scanf("%d",&veta[i]);
        for(int i=0;i<n;++i)scanf("%d",&vetb[i]);
        qsort(veta,n,sizeof(veta[0]),cmp2);
        qsort(vetb,n,sizeof(vetb[0]),cmp1);
        for(int i=0;i<n;++i)ret+=vetb[i]*veta[i];
        printf("case #%d:\n",a);
        printf("%d\n",ret);
        a++;
    }
    return 0;
}