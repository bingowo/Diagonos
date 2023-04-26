#include<stdio.h>
#include<string.h>
long long int res[50][50]; int midx[50], nidx = 2;

void Init(){
    for (int i = 0; i != 50; i++)
        res[i][0] = 1, midx[i] = 1;
    res[1][1] = 1;
    midx[1] = 2;
}

long long comb(int m, int n){
    if (m > n) return 0;
    if (m < midx[n] && n < nidx) return res[n][m];
    int nt = nidx;
    for (; nt <= n; nt++){
        for (; midx[nt] <= m; midx[nt]++)
            res[nt][midx[nt]] = res[nt-1][midx[nt] - 1] + res[nt-1][midx[nt]];
        if (midx[nidx] > nidx) nidx++;
    }
    return res[n][m];
}

int main(){
    int pro; scanf("%d", &pro);
    Init();
    for (int i = 0; i != pro; i++){
        printf("case #%d:\n", i);
        int n, m; scanf("%d%d", &n, &m);
        printf("%lld\n", comb(m,n));
    }
}