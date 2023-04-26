#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <memory.h>

typedef long long ll;
typedef unsigned long long ull;

char b[65]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

char* Base64(char* r, char* s){
    char rl=0;
    char rs=0;
    int j=0;
    for(int i=0;s[i]!='\0';i++){
        r[j++]=b[(s[i]>>(2+rl))|(rs<<6-rl)];
        rl=2+rl;
        rs=s[i]&((1<<rl)-1);
        if(rl==6){
            r[j++]=b[rs];
            rl=rs=0;
        }
    }
    if(rl){
        r[j++]=b[rs<<6-rl];
    }

    if(rl==4) rl=1;
    while(rl){
        r[j++]='=';
        rl--;
    }
    r[j]='\0';
    return r;
}

int main(){
    int pros;
    char s[105],r[150];
    scanf("%d",&pros);
    for(int now_cnt=0;now_cnt<pros;now_cnt++){
        scanf("%s",s);
        printf("case #%d:\n",now_cnt);
        printf("%s\n",Base64(r,s));
    }


    return 0;
}
