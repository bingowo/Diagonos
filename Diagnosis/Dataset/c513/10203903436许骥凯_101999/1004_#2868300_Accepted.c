#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void Print(unsigned char* p, int size){
    for (int i = 0; i != size && printf("%02x ", *p++); i++);
    printf("\n");
}

int main(){
    char num[20];
    while(~scanf("%s", num)){
        if (strchr(num, '.') != NULL){
            double temp = atof(num);
            Print((unsigned char*)&temp, sizeof(temp));
        }
        else{
            int temp = atoi(num);
            Print((unsigned char*)&temp, sizeof(temp));
        }   
    }
    return 0;
}