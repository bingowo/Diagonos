#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a,const void*b){
    int x=0,y=0;
    unsigned long long int m,n;
    m=*(long long int*)a;
    n=*(long long int*)b;
    while(m){
        x=x+(m&1);
        m=m>>1;
    }
     while(n){
        y=y+(n&1);
        n=n>>1;
    }
    if(x==y)
        return *(long long int*)a-*(long long int*)b;
    else
        return y-x;
}

int main(){
    int T;
    scanf("%d\n",&T);
    for(int cas=0;cas<T;cas++){
        int N;
        scanf("%d\n",&N);
        long long int a[N];
        for(int i=0;i<N;i++) scanf("%lld",&a[i]);
        qsort(a,N,sizeof(a[0]),cmp);
        printf("case #%d:\n",cas);
        for(int i=0;i<N-1;i++) printf("%lld ",a[i]);
        printf("%lld\n",a[N-1]);
    }
    return 0;
}
