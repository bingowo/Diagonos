#include <stdio.h>
#include <stdlib.h>

/***Q:why sort by ssurface***/

typedef struct{
    long long int R,H,s;
} GEO;

int cmp(const void *a, const void *b){
    long long int sa,sb;
    sa = ((GEO*)a)->s, sb = ((GEO*)b)->s;
    if(sa > sb) return -1;
    if(sa < sb) return 1;
    return 0;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);

    GEO input[1000];

    for(int i = 0; i < n; i++){
        scanf("%lld%lld",&input[i].R,&input[i].H);
        input[i].s = 2 * input[i].R * input[i].H + input[i].R * input[i].R;
    }

    qsort(input,n,sizeof(GEO),cmp);

    long long int ans = input[0].s;
    for(int i = 1; i < m; i++){
        ans += input[i].s - input[i].R * input[i].R;
    }

    printf("%lld",ans);

    return 0;
}
