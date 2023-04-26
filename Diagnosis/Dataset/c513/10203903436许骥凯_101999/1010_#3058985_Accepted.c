#include<stdio.h>
#include<string.h>

void PrintWithB(int num, int len){
    if (len == 0) return;
    PrintWithB(num / 2, len - 1);
    printf("%d", num % 2);
}

void Print(char *s, int idx, int len){
    if (len == 0) return;
    int temp = 0;
    for (int i = 0; i != len; ++i)
        temp = temp * 10 + s[i + idx] - '0';
    if (len == 1) PrintWithB(temp, 4);
    else if (len == 2) PrintWithB(temp, 7);
    else if (len == 3) PrintWithB(temp, 10);
}

int main(){
    char s[500]; scanf("%s", s); printf("0001");
    int slen = strlen(s); PrintWithB(slen, 10);
    
    int i = 0;
    for (; i < slen - 2; i += 3) Print(s, i, 3);
    Print(s, i, slen - i); printf("\n");
    return 0;
}