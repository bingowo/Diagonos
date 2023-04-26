#include <stdio.h>
#include <string.h>
#include <math.h>
int Gcd(int x, int y) {
    if (x % y == 0)
        return y;
    return Gcd(y, x % y);
}

void Solution(char *s) {
    int Tab[] ={0, 1, -1};
    int point = 0;
    int len = strlen(s);
    int i;
    for (point = 0; point < len; point++)
        if (s[point] == '.')
            break;
    
    // if (point == len)   //没有小数部分

    long long a = 0;  //整数部分
    for (i = 0; i < point; i++){
        a = a * 3 + Tab[s[i] - '0'];
    }
    int b = 0, c = 1;   //b为分子，c为分母
    for (i = len - 1; i > point; i--) {
        
        b  = b * 3 + Tab[s[i] - '0'];
        c *= 3;
    }

    if (b) {
        int gcd = abs(Gcd(c,b));
        b /= gcd;
        c /= gcd;
    }

    if (a && b < 0) {
        a--;
        b = c + b;
    }else if (a < 0 && b) {
        a++;
        b = c - b;
    }

    if (a)
        printf("%lld", a);
    if (b) {
        if (a)
            printf(" ");
        printf("%d %d", b, c);
    }

    if (!a && !b)
        printf("0");
}

int main(){
    char s[31];
    scanf("%s", s);
    Solution(s);
    return 0;
}