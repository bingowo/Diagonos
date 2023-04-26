#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 32769

void process(char s[N], int len){
    int newlen = len*2;
    for(int i = len; i < newlen; i++)
        s[i] = (s[i-len] == '0' ? '1' : '0');
}

int main()
{
    int i;
    scanf("%d",&i);

    char s[N] = {'0'};
    int len = 1;

    for(int j = 0; j < i; j++){
        process(s,len);
        len *= 2;
    }

    s[len] = '\0';
    printf("%s\n",s);

    return 0;
}
