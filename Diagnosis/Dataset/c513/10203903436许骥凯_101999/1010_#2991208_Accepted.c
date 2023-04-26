#include<stdio.h>
#include<string.h>

void trans(int n, int len){
    int res[10], rlen = 0;
    for (int i = 0; i != len; i++){
        res[rlen++] = n % 2;
        n /= 2;
    }
    for (int i = rlen - 1; i >= 0; i--) printf("%d", res[i]);
}

int bin(char *s, int len){
    int res = 0; 
    for (int i = 0; i != len; i++)
        res = res * 10 + s[i] - '0';
    return res;
}

int main(){
    char s[500]; scanf("%s", s);
    int slen = strlen(s);
    printf("0001");
    trans(slen, 10);
    int i;
    for (i = 0; i < slen - 2; i += 3)
        trans(bin(s + i, 3), 10);
    if (i == slen - 1) trans(bin(s + i, 1), 4);
    else if (i == slen - 2) trans(bin(s + i, 2), 7);
    return 0;
}