#include<stdio.h>

int main(){
    int T; scanf("%d", &T);
    for (int i = 0; i != T; ++i){
        int x, y; scanf("%d%d", &x, &y);
        int t = x ^ y;
        int cnt = 0;
        for (int j = 0; j != 32; ++j){
            cnt += 1 & t;
            t >>= 1;
        }
        printf("%d\n", cnt);
    }
    return 0;
}