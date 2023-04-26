#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 102

int main()
{
    int T;
    for(scanf("%d",&T); T > 0; T--){
        int in[M] = {0}, out[M] = {0}, ans[M][M] = {{0}};
        int n,a,b,res = 1;
        for(scanf("%d",&n); n > 0; n--){
            scanf("%d%d",&a,&b);
            if(a == b || ans[a][b]) continue;
            ans[a][b] = 1;
            //a-b b-c; a-b a-c; c-a a-b
            if(in[b] || out[a] || in[a]){
                res = 0;
                break;
            }
            in[a] = 1, out[b] = 1;
        }
        puts(res ? "Lucky dxw!" : "Poor dxw!");
    }
    return 0;
}
