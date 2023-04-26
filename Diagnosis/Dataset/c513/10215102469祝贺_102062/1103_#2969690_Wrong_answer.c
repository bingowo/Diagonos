#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
long long getn(long long t){
    return (long long)((sqrt(4*t+1)-1)/2);
}

void operate(int* tab,char* order,char* op1,char*op2){
    if(strcmp(order,"IN")==0){
        int num=atoi(op2);
        tab[op1[0]-'A']=num;
        return;
    }
    else{
        int a=op1[0]-'A',b=op2[0]-'A';
        if(strcmp(order,"MOV")==0){tab[a]=tab[b];}
        else if(strcmp(order,"ADD")==0){tab[a]+=tab[b];}
        else if(strcmp(order,"SUB")==0){tab[a]-=tab[b];}
        else if(strcmp(order,"MUL")==0){tab[a]*=tab[b];}
        else if(strcmp(order,"DIV")==0){tab[a]/=tab[b];}
        return;
    }
}
int main(){
    char order[5];
    int tab[4]={0};
    while(scanf("%s",order)!=EOF){
        if(strcmp(order,"OUT")==0){
            char s[5];scanf("%s",s);
            printf("%d",tab[s[0]-'A']);
        }
        else{
            char op1[5],op2[20];scanf("%s",op1);
            strcpy(op2,op1+3);
            operate(tab,order,op1,op2);
        }
    }
    return 0;
}

