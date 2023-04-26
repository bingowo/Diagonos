#include <stdio.h>
#include <stdlib.h>

static int flag = 0;

typedef struct{
    long long int R,H,s;
} GEO;

int cmp_side(const void *a, const void *b){
    long long int sa,sb;
    sa = ((GEO*)a)->s, sb = ((GEO*)b)->s;
    if(sa > sb) return -1;
    if(sa < sb) return 1;
    flag++;
    return 0;
}


int main()
{
    int n,m;
    scanf("%d%d",&n,&m);

    GEO input[1000];

    for(int i = 0; i < n; i++){
        scanf("%lld%lld",&input[i].R,&input[i].H);
        input[i].s = input[i].R * input[i].H;
    }

    qsort(input,n,sizeof(GEO),cmp_side);

    long long int ans = 0;
    for(int i = 0; i < m; i++){
        ans += input[i].s;
    }

    long long int maxR = 0;
    for(int i = 0; i < m + flag; i++){
        maxR = maxR > input[i].R ? maxR : input[i].R;
    }
    ans = ans * 2 + maxR * maxR;

    printf("%lld",ans);

    return 0;
}
