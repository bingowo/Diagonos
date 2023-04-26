#include<stdio.h>
#include<string.h>

void print(int n, int len){
    if (len == 0) return;
    else{
        print(n / 2, len - 1);
        printf("%d", n % 2);
    } 
}

int trans(char *s, int len){
    int res = 0;
    for (int i = 0; i != len; i++)
        res = res * 10 + s[i] - '0';
    return res;
}


int main(){
    char s[500]; scanf("%s", s); int slen = strlen(s);
    printf("0001");
    print(slen, 10);

    int i = 0;
    for (; i < slen - 2; i += 3) print(trans(s + i, 3), 10);
    if (i == slen - 2) print(trans(s + i, 2), 7);
    else if (i == slen - 1) print(trans(s + i, 1), 4);
    printf("\n");
    return 0;
}