#include<stdio.h>
#include<stdlib.h>
int binary(long long int a){
    int m=0;
    long long int n=1;
    for(int i = 64;i>0;i--,a=a>>1)m+=(a&n);
    return m;
}
int cmp(const  void *a,const void *b){
    int m,n;
    long long int a1,b1;
    a1 = *(long long int *)a,b1 = *(long long int *)b;
    m=binary(a1);
    n=binary(b1);
    if (m>n)return -1;
    else return 1;
}
int main(){
    int T,N,order=0;
    scanf("%d",&T);
    while(T-->0){
        scanf("%d",&N);
        long long int m[N];
        int i = 0;
        while(N-->0)scanf("%lld",&m[i++]);
        qsort(m,i,sizeof(long long int),cmp);
        printf("case #%d:\n",order++);
        for(int p = 0;p<i;p++)printf("%lld ",m[p]);
        printf("\n");
    }
    return 0;
}
