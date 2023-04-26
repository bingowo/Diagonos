#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define LEN 105
#define BigNUm 1000000007
#define Max 1000000



int main() {
    int T;
    scanf("%d",&T);
    for(int I=0; I<T; I++) {
        int n;
        scanf("%d",&n);
        int end[LEN],start[LEN],ab[LEN][LEN];
        memset(start,0,sizeof(start));
        memset(end,0,sizeof(end));
        memset(ab,0,sizeof(ab));
        int ans=1;
        for(int i=0; i<n; i++) {
            int a,b;
            scanf("%d%d",&a,&b);
            if(ab[a][b]==1||a==b) continue;
            ab[a][b]=1;
            if(start[b]==1||end[a]==1||start[a]==1) {
                ans=0;
                break;
                
                
                
            }
            start[a]=end[b]=1;
        }
        puts(ans==1?"Lucky dxw!":"Poor dxw!");


    }
    return 0;
}
