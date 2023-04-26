#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 100000

typedef struct{
    char c;
    int cnt;
} PAIR;

int cmp(const void* m, const void* n) {
    return *(int*)m - *(int*)n;
}

int judge(int* max, int n, PAIR **f) {
    for(int i=1; i<n; ++i)
        if(max[i] != max[0]) return 0;
    for(int j=0; j<=max[0]; ++j)
        for(int i=1; i<n; ++i)
            if(f[i][j].c != f[0][j].c) return 0;
    return 1;
}

int main()
{
    int n, max[N]={0};
    scanf("%d",&n);
    PAIR **f = (PAIR**)malloc(n*sizeof(PAIR*));
    for(int i=0; i<n; ++i) {
        f[i] = (PAIR*)malloc(100*sizeof(PAIR));
        char s[101];
        scanf("%s",s);
        for(int k=0; s[k]; ++k) {
            if(k==0) {
                f[i][0].c = s[0];
                f[i][0].cnt = 1;
            }else if(s[k] == s[k-1]) {
                ++f[i][max[i]].cnt;
            }else {
                ++max[i];
                f[i][max[i]].c = s[k];
                f[i][max[i]].cnt = 1;
            }
        }
    }
    if(! judge(max, n, f)){
        printf("-1\n");
        return 0;
    }
    int* a = malloc(n*sizeof(int)), sum=0;
    for(int i=0; i<=max[0]; ++i) {
        for(int k=0; k<n; ++k)
            a[k] = f[k][i].cnt;
        qsort(a, n, sizeof(int), cmp);
        for(int k=0; k<n; ++k) sum += abs(a[k]-a[n/2]);
    }
    printf("%d\n",sum);
    for(int i=0; i<n; ++i) free(f[i]);
    free(a);  free(f);
    return 0;
}
