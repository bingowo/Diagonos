#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int s[1000];
int w[100];
int sign[3] = {1,0,-1};

void dfs(int val, int pos) {
    if(pos == -1) return;
    for(int i=0; i<3; ++i) {
        int next = val + sign[i] * w[pos];
        s[abs(next)] = 1;
        dfs(next, pos-1);
    }
}

int main()
{
    int n, len = 0;
    scanf("%d",&n);
    for(int i=0; i<n; ++i) {
        scanf("%d",&w[i]);
        len += w[i];
    }
    dfs(0, n-1);
    for(int i=1; i<=len; ++i) printf("%d",s[i]);
    printf("\n");
    return 0;
}
