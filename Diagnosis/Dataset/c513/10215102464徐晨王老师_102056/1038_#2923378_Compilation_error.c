#include <stdio.h>
#include <stdlib.h>
int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int ans=0;
    for (int x0 = 1; x0 <= N; x0++) {
        for (int y0 = 1; y0 <= M; y0++) {		
            long long s = a[x0][y0];
            for (int r = 1; x0 - r > 0 && y0 - r > 0; r++) {
                int lb = y0 - r;				
                int rb = y0;
                for (int y = lb; y <= rb; y++)
                    s += a[x0 - r][y];
                if (s >= K) ans++;
            }
    printf("%d",ans);
    return 0;

}