//1077
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int X[4];
void IN(char *s){
    int num = atoi(s+3);
    X[s[0]-65] = num;
}
void MUL(char *s){
    X[s[0]-65] *= X[s[3]-65];
}
void ADD(char *s){
    X[s[0]-65] += X[s[3]-65];
}
void SUB(char *s){
    X[s[0]-65] -= X[s[3]-65];
}
void DIV(char *s){
    X[s[0]-65] /= X[s[3]-65];
}
void MOV(char *s){
    X[s[0]-65] = X[s[3]-65];
}
void OUT(char *s){
    printf("%d\n", X[s[0]-65]);
}
int main(){
    char order[5], factor[20];
    while(scanf("%s", order) != EOF){
        scanf("%s", factor);
        if(strcmp(order, "IN") == 0){
            IN(factor);
        }else if(strcmp(order, "MUL") == 0){
            MUL(factor);
        }else if(strcmp(order, "ADD") == 0){
            ADD(factor);
        }else if(strcmp(order, "DIV") == 0){
            DIV(factor);
        }else if(strcmp(order, "MOV") == 0){
            MOV(factor);
        }else if(strcmp(order, "SUB") == 0){
            SUB(factor);
        }else{
            OUT(factor);
        }
    }
    return 0;
}