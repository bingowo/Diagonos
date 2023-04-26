#include<stdio.h>

int main(){
    int T; scanf("%d", &T);
    while(T--){
        int x, y; scanf("%d%d", &x, &y);
        int cnt = 0;
        for (int i = 0; i != 32; i++){
            if ((x & 1) ^ (y & 1)) cnt++;
            x >>= 1; y >>= 1;
        }
        printf("%d\n", cnt);
    }
    return 0;
}