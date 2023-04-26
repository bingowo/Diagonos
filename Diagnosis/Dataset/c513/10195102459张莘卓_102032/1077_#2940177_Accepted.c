#include <stdio.h>
#include <stdlib.h>

int rank[1001]={0};
int cmp1(const void* a, const void* b){
    return rank[*(int*)a] - rank[*(int*)b];
}
int cmp2(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int main()
{
    int m, n, a, cnt=0, b1[500], b2[500];
    scanf("%d",&m);
    for(int i=0; i<m; ++i) {
        scanf("%d",&a);
        rank[a] = i + 1;
    }
    scanf("%d",&n);
    for(int i=0; i<n; ++i){
        scanf("%d",&a);
        if(rank[a]) b1[cnt++] = a;
        else b2[i-cnt] = a;
    }
    qsort(b1, cnt, sizeof(int), cmp1);
    qsort(b2, n-cnt, sizeof(int), cmp2);
    for(int i=0; i<n-cnt; ++i) b1[cnt+i] = b2[i];
    for(int i=0; i<n; ++i)
        printf("%d%s",b1[i],i<n-1?" ":"\n");
    return 0;
}
