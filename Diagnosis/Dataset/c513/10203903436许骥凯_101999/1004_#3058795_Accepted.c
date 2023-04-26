#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void Print(const void *data, int len){
    unsigned char *temp = (unsigned char *)data;
    for (int i = 0; i != len; ++i)
        printf("%02x%c", *(temp + i), (i == len - 1? '\n': ' '));
}

int main(){
    char s[1000];
    while(scanf("%s", s) != EOF){
        if (strchr(s, '.')){
            double d = atof(s);
            Print(&d, sizeof(d));
        }    
        else{
            int i = atoi(s);
            Print(&i, sizeof(i));
        }
    }
    return 0;
}