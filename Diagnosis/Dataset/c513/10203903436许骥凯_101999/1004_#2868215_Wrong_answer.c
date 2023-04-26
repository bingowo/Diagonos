#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char num[20];
    while(~scanf("%s", num)){
        void* p = NULL; int sz;

        if (strchr(num, '.') != NULL){
            double temp = atof(num);
            p = &temp; sz = sizeof(temp);
        }
        else{
            int temp = atoi(num);
            p = &temp; sz = sizeof(temp);
        }

        unsigned char* res = (unsigned char*)p;
        for (int i = 0; i != sz; i++)
            printf("%02x ", *res++);
        printf("\n");
            
    }
    return 0;
}