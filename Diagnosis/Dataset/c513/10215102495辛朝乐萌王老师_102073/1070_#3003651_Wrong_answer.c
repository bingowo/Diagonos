#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define LEN 110

int map[21];

void solve(void)
{
    map[0]=1,map[1]=2,map[2]=4,map[3]=7;
    for (int i=0; i<4; i++) {
        map[i]=2*map[i-1];
        for (int j=i-3,sgn=-1;j>=0; j-=2) {
            map[i]+=sgn*map[j];
            sgn*=-1;
        }
    }
}

int main()
{
    int n;
    solve();
    scanf("%d",&n);
    while (n!=-1) {
        printf("%d",map[n]);
        scanf("%d",&n);
    }
    return 0;
}
