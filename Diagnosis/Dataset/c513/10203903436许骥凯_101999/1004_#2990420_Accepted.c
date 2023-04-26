#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define uc unsigned char

void process(uc *p, int n){
    while(n--) printf("%02x%c", *p++, n == 0? '\n': ' ');
}


int main(){
    char s[100]; 
    while(~scanf("%s", s)){ 
        if (strchr(s, '.')){
            double t = atof(s);
            process((uc*)&t, sizeof(t));
        }
        else{
            int t = atoi(s);
            process((uc*)&t, sizeof(t));
        }
    }
    return 0;
}