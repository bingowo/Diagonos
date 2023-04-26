#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
long long int trans(long long int *a){
    long long int n,*b,c;
    c=*a;
    if(c<0ll)n=-c;
    while(n>=10){
        n/=10;
    }
    return n;
}
int cmp(const void *a,const void *b){
    long long int *a1,*a2,n1,n2;
    a1=(long long int *)a;
    a2=(long long int *)b;
    n1=trans(a1);
    n2=trans(a2);
    if(n1==n2){
        if(*a1>*a2)return 1;
        return -1;
    }
    if(n1>n2)return 1;
    return -1;




}
int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int N;
        scanf("%d",&N);
        long long int *num;
        num=(long long int*)malloc(N*sizeof(long long int));
        for(int m=0;m<N;m++){
            scanf("%lld",&*(num+m));
        }
        qsort(num,N,sizeof(long long int),cmp);
        printf("case #%d:\n",i);
        for(int k=0;k<N-1;k++)printf("%lld ",*(num+k));
        printf("%lld\n",*(num+N-1));



    }






}