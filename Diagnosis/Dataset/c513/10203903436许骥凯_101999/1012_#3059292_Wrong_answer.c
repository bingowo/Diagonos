#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

void CompToAB(char *s, long long *a, long long *b){
    *a = 0, *b = 0;
    int len = strlen(s);
    if (s[len - 1] != 'i'){
        *a = atoi(s); *b = 0;
        return ;
    }

    int var = 0, i = 0, flag = 1;
    if (s[i] == '+' || s[i] == '-'){
        if (s[i] == '-') flag = -1;
        ++i;
    }

    for (; isdigit(s[i]); ++i)
        var = var * 10 + s[i] - '0';
    if (s[i] == 'i'){
        *a = 0; *b = var * flag;
        return ;
    }

    *a = var * flag;
    flag = (s[i] == '-'? -1: 1);
    for (++i; isdigit(s[i]); ++i)
        *b = *b * 10 + s[i] - '0';
    if (*b == 0) *b = 1;
    *b *= flag;
    return;
}

void CalPrint(long long qr, long long qi, int r){
    if (qi == 0 && qr == 0)
        return ;

    r = (qr % 2 == 0) ^ (qi % 2 == 0);

    long long temp = qr;
    qr = (qi - qr + r) / 2;
    qi = (r - temp - qi) / 2; 
    CalPrint(qr, qi, r);
    printf("%d", r);
}

int main(){
    char s[40]; scanf("%s", s);
    long long a = 0, b = 0; CompToAB(s, &a, &b);
    int r = 0;
    CalPrint(a, b, r);
    if (a == 0 && b == 0) printf("0");
    printf("\n");
    return 0;
}