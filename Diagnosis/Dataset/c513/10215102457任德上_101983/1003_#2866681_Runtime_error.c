#include<stdio.h>
#include<stdlib.h>
int cmp(const  void *a,const void *b){
    int m,n,a1,b1;
    a1 = *(int*)a,b1 = *(int*)b;
    m=binary(a1);
    n=binary(b1);
    if (m>n)return -1;
    else
        return 1;
}
int binary(int a){
    int i = 64,m=0,n=1;
    while(i-->0){
        m+=(a&n);
        n<<1;
    }
    return m;
}
int main(){
    int T,N,order=0;
    long long int m[10000];
    scanf("%d",&T);
    while(T-->0){
        scanf("%d",&N);
        int i = 0;
        while(N-->0)scanf("%lld",m[i++]);
        qsort(m,i,sizeof(long long int),cmp);
        printf("case #%d",order++);
        for(int p = 0;p<i;p++)printf("%d",m[p]);
    }
    return 0;
}