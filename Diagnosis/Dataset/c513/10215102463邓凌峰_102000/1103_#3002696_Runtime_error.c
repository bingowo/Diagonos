#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define LEN 110
#define BigNUm 1000000007
#define Max 1000000

int R[4];

void IN(char *right){
    char tmp=right[0];
    int num=0,idx=3;
    while(isdigit(right[idx])){
        num=num*10+right[idx++]-'0';
    }
    R[tmp-'A']=num;
}

void MOV(char *right){
    char AX=right[0],BX=right[3];
    R[AX-'A']=R[BX-'A'];
}

void ADD(char *right){
    char AX=right[0],BX=right[3];
    R[AX-'A']=R[AX-'A']+R[BX-'A'];
}

void SUB(char *right){
    char AX=right[0],BX=right[3];
    R[AX-'A']=R[AX-'A']-R[BX-'A'];
}

void MUL(char *right){
    char AX=right[0],BX=right[3];
    R[AX-'A']=R[AX-'A']*R[BX-'A'];
}

void DIV(char *right){
    char AX=right[0],BX=right[3];
    R[AX-'A']=R[AX-'A']/R[BX-'A'];
}

void OUT(char *right){
    char AX=right[0];
    printf("%d\n",R[AX-'A']);
}

int main() {


    char left[10]={0},right[20];
    while(scanf("%s",left)!=EOF){
        scanf("%s",right);
        if(strcmp(left,"IN")==0) IN(right);
        else if(strcmp(left,"MOV")==0) MOV(right);
        else if(strcmp(left,"ADD")==0) ADD(right);
        else if(strcmp(left,"SUB")==0) SUB(right);
        else if(strcmp(left,"MUL")==0) MUL(right);
        else if(strcmp(left,"DIV")==0) DIV(right);
        else if(strcmp(left,"OUT")==0) OUT(right);
    }



    return 0;
}
