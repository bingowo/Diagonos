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

/*int cmp_bottom(const void *a, const void *b){
    long long int sa,sb;
    sa = ((GEO*)a)->R, sb = ((GEO*)b)->R;
    if(sa > sb) return -1;
    if(sa < sb) return 1;
    return 0;
}*/

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

    long long int ans = 0, temp = 0;
    for(int i = 0; i < n; i++){
        temp = 2 * input[i].s + input[i].R * input[i].R;
        int count = 1;
        for(int j = 0; j < n && count < m; j++){
            if(i==j || input[j].R > input[i].R) continue;
            temp += 2 * input[j].s;
            count++;
        }
        if(count == m) ans = ans > temp ? ans : temp;
    }


    printf("%lld",ans);

    return 0;
}
