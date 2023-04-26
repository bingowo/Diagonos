#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
int atoii(char* s){
    int sign=1,num=0;
    if(!isdigit(s[0])){
        if(s[0]='-')num=-atoi(s+1);
        else num=atoi(s+1);
    }
    else num=atoi(s);
    return num;
}
void operate(int* tab,char* order,char* op){
    char op2[30]={0};strcpy(op2,op+3);
    char op3[30]={0};if(strlen(op)>=6) strcpy(op3,op+6);
    if(strcmp(order,"IN")==0){
        int num=atoii(op2);
        tab[op[0]-'A']=num;
        return;
    }
    else{
        int a=op[0]-'A',b=op2[0]-'A',c=op3[0]-'A';
        if(strcmp(order,"MOV")==0){tab[a]=tab[b];}
        else if(strcmp(order,"XCHG")==0){int c=tab[a];tab[a]=tab[b];tab[b]=c;}
        else if(strcmp(order,"ADD")==0){tab[a]=(strlen(op3)>0?tab[b]+tab[c]:tab[a]+tab[b]);}
        else if(strcmp(order,"SUB")==0){tab[a]=(strlen(op3)>0?tab[b]-tab[c]:tab[a]-tab[b]);}
        else if(strcmp(order,"MUL")==0){tab[a]=(strlen(op3)>0?tab[b]*tab[c]:tab[a]*tab[b]);}
        else if(strcmp(order,"DIV")==0){tab[a]=(strlen(op3)>0?tab[b]/tab[c]:tab[a]/tab[b]);}
        else if(strcmp(order,"MOD")==0){tab[a]=(strlen(op3)>0?tab[b]%tab[c]:tab[a]%tab[b]);}
        else if(strcmp(order,"AND")==0){tab[a]=(strlen(op3)>0?tab[b]&tab[c]:tab[a]&tab[b]);}
        else if(strcmp(order,"OR")==0){tab[a]=(strlen(op3)>0?tab[b]|tab[c]:tab[a]|tab[b]);}
        else if(strcmp(order,"XOR")==0){tab[a]=(strlen(op3)>0?tab[b]^tab[c]:tab[a]^tab[b]);}
        
        return;
    }
}
int main(){
    char order[5],op[30];
    int tab[30]={0};
    while(scanf("%s%s",order,op)!=EOF){
        if(strcmp(order,"OUT")==0){
            printf("%d\n",tab[op[0]-'A']);
        }
        else{
            operate(tab,order,op);
        }
    }
    return 0;
}

