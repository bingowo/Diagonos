#include <stdio.h>
#include <stdlib.h>

int get(long long a){
    int cnt=0;
    long long x=1;
    for(int i=0;i<64;i++){
        if((a & (x<<i))==(x << i))
            cnt++;
    }
    return cnt;
}

int cmp(const void *a,const void *b){
    int x,y;
    x=get(*(long long *)a);
    y=get(*(long long *)b);
    if(x!=y)
        return y-x;
    else
        return *(long long *)a-*(long long *)b;
}
int main()
{
    int T,N;
    long long a[10000];
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d",&N);
        for(int j=0;j<N;j++){
            scanf("%lld",&a[j]);
        }
        qsort(a,N,sizeof(long long),cmp);
        printf("case #%d:\n",i);
        for(int k=0;k<N;k++){
            printf("%lld ",a[k]);
            if(k==N-1)
                printf("\n");
        }
    }
    return 0;
}
