#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char st[100010];

int check();

int main(){
    while (scanf("%s",st)!=EOF){
        if (check()){
            int ansint=atoi(st);
            for (int i=1;i<=4;i++){
                int t=~(~0<<8)&ansint;
                printf("%02x ",t);
                ansint>>=8;
            }
            printf("\n");
        }
        else{
            double ansdouble=atof(st);
            unsigned long long ansd=*(unsigned long long*)(&ansdouble);
            for (int i=1;i<=8;i++){
                unsigned long long t=~(~0<<8)&ansd;
                printf("%02x ",t);
                ansd>>=8;
            }
            printf("\n");
        }
    }
    return 0;
}

int check(){
    for (int i=0;i<strlen(st);i++){
        if (st[i]=='.') return 0;
    }
    return 1;
}



