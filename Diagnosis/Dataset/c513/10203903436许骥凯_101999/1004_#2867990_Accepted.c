#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char num[20];
    while (~scanf("%s", num)){
        if (strchr(num, '.') != NULL){
            double temp = atof(num);
            int sz = sizeof(temp);
            int i = 0;
            for (unsigned char* p = (unsigned char*)&temp; i != sz; p++, i++)
                printf("%02x ", *p);
            printf("\n");
        }
        else{
            int temp = atoi(num);
            int sz = sizeof(temp);
            int i = 0;
            for (unsigned char *p = (unsigned char*)&temp; i != sz; p++, i++)
                printf("%02x ", *p);
            printf("\n");
        }
    }
    return 0;
}