#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    int table[128] = {0};
    for (int i = 0; i <= 128; i++)
        table[i] = -1;
    for (int i = 0; i <= 128; i++){
        if (i >= 'a' && i <= 'f') table[i] = 10 + i - 'a';
        else if (i >= '0' && i <= '9') table[i] = i - '0';
    }
    printf("%d\n", table[0]);

}
