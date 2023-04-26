#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

void CompToAB(char *s, long long *a, long long *b){
    int len = strlen(s);
    if (s[len - 1] != 'i') *a = atoll(s);
    else if (strcmp(s, "i") == 0) *b = 1;
    else if (strcmp(s, "-i") == 0) *b = -1;
    else{
        long long var = 0; int i = 0, flag = 1;
        if (s[i] == '-') flag = -1, ++i;
        for (; isdigit(s[i]); ++i)
            var = var * 10 + s[i] - '0';
        if (s[i] == 'i') *b = var * flag;
        else{
            *a = var * flag;
            flag = (s[i] == '-'? -1: 1);
            if (s[++i] == 'i') *b = 1;
            else{
                for (; isdigit(s[i]); ++i)
                    *b = *b * 10 + s[i] - '0';
            }
            *b = *b * flag;
        }
    }
}

void CalPrint(long long a, long long b, int r){
    if (a == 0 && b == 0) return ;
    r = (a % 2 == 0) ^ (b % 2 == 0);
    long long temp = a;
    a = (b - a + r) / 2;
    b = (r - temp - b) / 2;
    CalPrint(a, b, r);
    printf("%d", r);
}

int main(){
    char s[40]; scanf("%s", s);
    long long a = 0, b = 0; int r = 0; CompToAB(s, &a, &b);
    CalPrint(a, b, r);
    if (a == 0 && b == 0) printf("0");
    printf("\n");
    return 0;
}