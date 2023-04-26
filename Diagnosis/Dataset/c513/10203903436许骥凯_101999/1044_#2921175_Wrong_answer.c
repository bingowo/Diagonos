#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char *s = (char*)malloc(sizeof(char) * 100001);
    int table[128] = {0};
    for (int i = 0; i <= 128; i++)
        table[i] = -1;
    for (int i = 0; i <= 128; i++){
        if (i >= 'a' && i <= 'f') table[i] = 10 + i - 'a';
        else if (i >= '0' && i <= '9') table[i] = i - '0';
    }
    scanf("%s", s);
    unsigned int sum = 0; int i = 0, flag = 1;
    for (; i < strlen(s); i++){
        if (s[i] == 'x' && s[i-1] == '0'){
            i++;
            while(i < strlen(s) && table[s[i]] != -1)
               flag = 0, sum = table[s[i++]] + sum * 16;
            if (!flag) printf("%u ", sum);
            sum = 0;
        }
    }
    if (flag) printf("-1\n");
    free(s);
    return 0;

}
