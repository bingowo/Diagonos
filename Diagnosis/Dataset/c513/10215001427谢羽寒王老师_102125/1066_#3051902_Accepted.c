#include <stdio.h>
#include <stdlib.h>

int count,t,n;

void times(int p, int m){
    if (m <= 0){
        if (p == t) count++;
        return;
    }
    if (p == 1) times(2, m - 1);
    else if (p == n) times(n - 1, m - 1);
    else{
        times(p + 1, m - 1);
        times(p - 1, m - 1);
    }
}

int main(){
    int cas,p,m;
    scanf("%d", &cas);
    while (cas--){
        count = 0;
        scanf("%d%d%d%d",&n,&p,&m,&t);
        times(p,m);
        printf("%d\n", count);
    }
    return 0;
}
