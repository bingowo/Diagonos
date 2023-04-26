#include<stdio.h>
#define MAX(a, b) (a > b? a: b)

typedef int LEN;

LEN atoB(int n, int *s){
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
        int len = atoB(n, s);
        int max = 1, temp = 1;
        for (int i = 1; i != len; i++){
            if (s[i] != s[i-1]){
                temp++;
                max = MAX(max, temp);
            }
            else temp = 1;
        }
        printf("%d\n", max);
    }
    return 0;
}