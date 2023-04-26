#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char num[20];
    while(~scanf("%s", num)){
        if (strchr(num, '.') != NULL){
            double temp = atof(num);
            unsigned char* p = (unsigned char*)&temp;
            for (int i = 0; i != sizeof(temp) && printf("%02x ", *p++); i++);
            printf("\n");
        }
        else{
            int temp = atoi(num);
            unsigned char* p = (unsigned char*)&temp;
            for (int i = 0; i != sizeof(temp) && printf("%02x ", *p++); i++);
            printf("\n");
        }
    }
    return 0;
}