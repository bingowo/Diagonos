#include<stdio.h>
#include<string.h>
#include<stdlib.h>

union Data{
    double d;
    int i;
    unsigned char uc[32]; 
};

int main(){
    char s[1000]; 
    while(scanf("%s", s) != EOF){
        union Data dt; int len = 0;
        if (strchr(s, '.')){
            dt.d = atof(s);
            len = sizeof(dt.d);
        }
        else{    
            dt.i = atoi(s);
            len = sizeof(dt.i);
        }
        for (int i = 0; i != len; ++i)
            printf("%02x%c", dt.uc[i], (i == len - 1? '\n': ' '));
    }
    return 0;
}