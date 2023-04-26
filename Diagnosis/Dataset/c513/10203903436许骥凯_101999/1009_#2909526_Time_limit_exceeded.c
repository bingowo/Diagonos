#include<stdio.h>
#include<string.h>

int gcd(int a, int b){
    int temp;
    while (b != 0){
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main(){
    int T;
    scanf("%d", &T);
    getchar();
    for (int i = 0; i < T; i++){
        char s[200];
        gets(s);
        int top = 0, btm = 0;
        for (int j = 0, l = strlen(s); j < l; ++j){
            unsigned char ch = s[i];
            while (ch != 0){
                top += (ch & 1);
                ch >> 1;
            }
            btm += 8;
        }
        int g = gcd(top, btm);
        printf("%d/%d\n", top/g, btm/g);
    }
    return 0;
}