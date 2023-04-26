#include<stdio.h>

int main(){
    int T; scanf("%d", &T);
    for (int i = 0; i != T; ++i){
        printf("case #%d:\n", i);
        int n; scanf("%d", &n);
        int maxLen = 1, len = 1, forward = n % 2;
        do{
            n /= 2;
            if (n % 2 == forward){
                maxLen = (maxLen > len? maxLen: len);
                len = 1;
            }
            else{
                ++len;
                forward = n % 2;
            }
        }while(n / 2);
        maxLen = (maxLen > len? maxLen: len);
        printf("%d\n", maxLen);
    }
}