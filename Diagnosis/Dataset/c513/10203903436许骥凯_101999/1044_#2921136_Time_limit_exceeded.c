#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    int table[128]; 
    for (int i = 0; i <= 128; i++){
        if (i >= 'a' && i <= 'f') table[i] = 10 + i - 'a';
        else if (i >= '0' && i <= '9') table[i] = i - '0';
        else table[i] = -1;
    }
    for (int j = 0; j != 9; j++)
        printf("%d\n", table[j]);

}
