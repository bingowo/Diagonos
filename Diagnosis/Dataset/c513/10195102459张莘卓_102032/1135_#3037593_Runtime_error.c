#include <stdio.h>
#include <stdlib.h>
#define N 25

int a[101][N] = {{0},{1},{2},{3},{6}};

int main()
{
    int n;
    scanf("%d",&n);
    for(int t=5; t<=n; ++t) {
        int i=t-1, j=t-2, k=t-4;
        int carry=0;
        for(int cnt=0; cnt<N; ++cnt) {
            a[t][cnt] = a[i][cnt] + a[j][cnt] + a[k][cnt] + carry;
            carry = a[t][cnt] / 10;
            a[t][cnt] %= 10;
        }
    }
    int i = N-1;
    while(a[n][i] == 0) --i;
    while(i >= 0) printf("%d",a[n][i--]);
    printf("\n");
    return 0;
}
