#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int w[10];
int s[1001];

void dfs(int val, int pos) {
    if(pos == -1) return;
    for(int sign=-1; sign<=1; ++sign) {
        int next = val + sign * w[pos];
        s[abs(next)] = 1;
        dfs(next, pos-1);
    }
}

int main()
{
    int n, sum=0;
    scanf("%d",&n);
    for(int i=0; i<n; ++i){
        scanf("%d",&w[i]);
        sum += w[i];
    }
    dfs(0, n-1);
    for(int i=1; i<=sum; ++i)
        printf("%d",s[i]);
    printf("\n");
    return 0;
}
