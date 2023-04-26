#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
    long long int ia = *(long long int*)a, ib = *(long long int*)b;
    if(ia > ib) return 1;
    if(ia < ib) return -1;
    return 0;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);

    long long int* in = (long long int*)malloc(n*sizeof(long long int));
    for(int i = 0; i < n; i++){
        scanf("%lld",&in[i]);
    }

    qsort(in,n,sizeof(in[0]),cmp);  //as

    long long int ans = 0;
    for(int j = 0; j < m-1; j++){
        ans += (in[m-1] - in[j]);
    }

    printf("%lld",ans);

    return 0;
}
