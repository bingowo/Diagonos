#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char s[100];
    while (scanf("%s", &s) != EOF){
        double dnum = 0;
        int inum = 0;
        if(strchr(s, '.') != NULL){
            dnum = atof(s);
            int len = sizeof(dnum);
            unsigned char* point = (unsigned char*)&dnum;
            for (int i = 0; i < len; i++){
                printf("%02x ", *point);
                point++;
            }
        }
        else{
            inum = atoi(s);
            int len = sizeof(inum);
            unsigned char* point = (unsigned char*)&inum;
            for (int i = 0; i < len; i++){
                printf("%02x ", *point);
                point++;
            }
        }
    }
    return 0;
}