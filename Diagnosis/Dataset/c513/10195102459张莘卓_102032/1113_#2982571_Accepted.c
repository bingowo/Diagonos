#include <stdio.h>

int a[100][40] = {{0},{1},{1},{2}};
int cnt[100] = {1,1,1,1};

void mult2(int k) {
    int carry = 0;
    for(int i=0; i<cnt[k-1]; ++i) {
        a[k][i] = a[k-1][i] * 2 + carry;
        carry = a[k][i] / 10;
        a[k][i] %= 10;
    }
    cnt[k] = cnt[k-1];
    if(carry) a[k][cnt[k]++] = carry;
}

void minus(int i, int j) { // a[i] -= a[j]
    int tmp[40] = {0};
    for(int k=0; k<cnt[i]; ++k) {
        if(a[i][k] < a[j][k]) {
            a[i][k] += 10;
            int t = k + 1;
            while(a[i][t] == 0)  a[i][t++] = 9;
            --a[i][t];
        }
        tmp[k] = a[i][k] - a[j][k];
    }
    for(int k=0; k<40; ++k) a[i][k] = tmp[k];
}

int main()
{
    int i, k, n;
    scanf("%d %d",&k, &n);
    for(i=4; i<=k; ++i) mult2(i);
    for(i=k+1; i<n; ++i) {
        mult2(i);
        minus(i, i-k-1);
    }
    for(i=39; i>=0 && a[n-1][i]==0; --i);
    if(i < 0) ++i;
    for(; i>=0; --i) printf("%d",a[n-1][i]);
    printf("\n");
    return 0;
}
