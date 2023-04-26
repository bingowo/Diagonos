#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char num[20];
    while(~scanf("%s", num)){
        unsigned char* p = NULL; int sz;

        if (strchr(num, '.') != NULL){
            double temp = atof(num);
            p = (unsigned char*)&temp; sz = sizeof(temp);
        }
        else{
            int temp = atoi(num);
            p = (unsigned char*)&temp; sz = sizeof(temp);
        }

        for (int i = 0; i != sz; i++)
            printf("%02x ", *p++);
        printf("\n");
            
    }
    return 0;
}