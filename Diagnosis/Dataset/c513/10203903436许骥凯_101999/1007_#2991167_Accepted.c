#include<stdio.h>

typedef int LEN;
LEN itoB(int n, int *s){
    int len = 0; 
    do{
        s[len++] = n % 2;
        n /= 2;
    }while(n);
    return len;
}

int main(){
    int T; scanf("%d", &T);
    for (int i = 0; i != T; i++){
        printf("case #%d:\n", i);
        int n; scanf("%d", &n);
        int s[32];
        int len = itoB(n, s);
        int max = 1, temp = 1;
        for (int i = 0; i != len - 1; i++){
            if (s[i] == s[i + 1]){
                max = temp > max? temp: max;
                temp = 1;
                continue;
            }
            temp++;
        }
        if (temp > max) max = temp;
        printf("%d\n", max);
    }
    return 0;
}