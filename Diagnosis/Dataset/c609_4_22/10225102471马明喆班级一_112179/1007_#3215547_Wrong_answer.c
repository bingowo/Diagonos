#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a,const void*b){
    int x,y;
    unsigned long long int m,n;
    m=*(long long int*)a;
    n=*(long long int*)b;
    for(int i=0;i<32;i++){
        if((m>>i)&&1)
            x++;
    }
    for(int i=0;i<32;i++){
        if((n>>i)&&1)
            y++;
    }
    if(x==y)
        return *(int*)a-*(int*)b;
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
        for(int i=0;i<N;i++) scanf("%d",&a[i]);
        qsort(a,N,sizeof(a[0]),cmp);
        printf("case #%d:\n",cas);
        for(int i=0;i<N-1;i++) printf("%d ",a[i]);
        printf("%d\n",a[N-1]);
    }
    return 0;
}