#include<stdio.h>

int main(){
    int T; scanf("%d", &T);
    while(T--){
        int x, y; scanf("%d%d", &x, &y);
        int cnt = 0, ans = x ^ y; 
        for (int i = 0; i != 32; i++){
            if (ans & 1) cnt++;
            ans >>= 1;
        }
        printf("%d\n", cnt);
    }
    return 0;
}