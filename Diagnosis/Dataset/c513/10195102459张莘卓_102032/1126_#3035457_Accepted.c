#include <stdio.h>
#include <stdlib.h>

int bin[10000][64];
int num[10000][25];
int cmp(const void* pa, const void* pb) {
    long long a = *(long long*)pa, b = *(long long*)pb;
    if(b > a) return 1;
    else return -1;
}

int main()
{
    int n;
    long long a[10000];
    scanf("%d",&n);
    for(int i=0; i<n; ++i) {
        scanf("%lld",&a[i]);
        long long t = a[i];
        int cnt = 0;
        do {
            bin[i][cnt++] = t % 2;
        }while(t /= 2);
    }
    for(int j=0; j<64; ++j) {
        int sum = 0;
        for(int i=0; i<n; ++i) sum += bin[i][j];
        if(sum % 2) {
            printf("-1\n");
            return 0;
        }
    }
    qsort(a, n, sizeof(a[0]), cmp);
    --n;
    for(int i=0; i<n; ++i) {
        int cnt = 0;
        do {
            num[i][cnt++] = a[i] % 10;
        }while(a[i] /= 10);
    }
    int ans[25]={0}, i, carry=0;
    for(int j=0; j<25; ++j)
        for(int i=0; i<n; ++i) ans[j] += num[i][j];
    for(i=0; i<25; ++i) {
        ans[i] += carry;
        carry = ans[i] / 10;
        ans[i] %= 10;
    }
    while(ans[i] == 0) --i;
    while(i >= 0) printf("%d",ans[i--]);
    printf("\n");
    return 0;
}
