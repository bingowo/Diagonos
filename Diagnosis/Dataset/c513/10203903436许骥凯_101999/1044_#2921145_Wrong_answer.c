#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    int table[128]; 
    for (int i = 0; i <= 128; i++){
        table[i] = 0;
    }
    printf("%d\n", table[0]);

}
