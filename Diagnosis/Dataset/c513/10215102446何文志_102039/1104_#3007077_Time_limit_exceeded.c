#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* getRegister(char* s, int* r){
    if('A'<=s[0]&&s[0]<='Z'){
        int index = s[0] - 'A';
        return &r[index];
    }
    return NULL;
}
void setRegister(char* s, int* r, int n){
    if('A'<=s[0]&&s[0]<='Z'){
        int index = s[0] - 'A';
        r[index] = n;
    }
    return;
}
void printRegister(char* s, int* r){
    if('A'<=s[0]&&s[0]<='Z'){
        int index = s[0] - 'A';
        printf("%d\n",r[index]);
    }
    return;
}
int isMath(char* s){
    if(strcmp(s,"ADD")==0||strcmp(s,"SUB")==0||strcmp(s,"MUL")==0||strcmp(s,"DIV")==0
       ||strcmp(s,"MOD")==0||strcmp(s,"AND")==0||strcmp(s,"OR")==0||strcmp(s,"XOR")==0)
    {
        return 1;
    }
    return 0;
}
int main()
{
    int r[26]; memset(r,0,26*sizeof(int));
    while(1){
        char curOperation[5] = {0,0,0,0,0};
        scanf("%s ",curOperation);
        if(strcmp(curOperation,"IN")==0){
            char reg[3] = {0,0,0};
            int n = 0;
            scanf("%[A-Z],%d",reg,&n);
            setRegister(reg, r, n);
        }
        else if(strcmp(curOperation,"OUT")==0){
            char reg[3] = {0,0,0};
            scanf("%[A-Z]",reg);
            printRegister(reg,r);
        }
        else if(strcmp(curOperation,"MOV")==0){
            char reg1[3] = {0,0,0}, reg2[3] = {0,0,0};
            scanf("%[A-Z],%[A-Z]",reg1,reg2);
            int *p = getRegister(reg2, r);//寄存器的地址
            setRegister(reg1, r, *p);
        }
        else if(strcmp(curOperation,"XCHG")==0){
            char reg1[3] = {0,0,0}, reg2[3] = {0,0,0};
            scanf("%[A-Z],%[A-Z]",reg1,reg2);
            int *p1 = getRegister(reg1, r), *p2 = getRegister(reg2, r);//寄存器的地址
            setRegister(reg1, r, *p2);
            setRegister(reg2, r, *p1);
        }
        else if(isMath(curOperation)){
            char reg1[3] = {0,0,0}, reg2[3] = {0,0,0}, reg3[3] = {0,0,0};
            scanf("%[A-Z],%[A-Z],%[A-Z]",reg1,reg2,reg3);

            if(strlen(reg3)==0){//未读入reg3
                int* p1, *p2;//寄存器的地址
                p1 = getRegister(reg1, r);
                p2 = getRegister(reg2, r);
                if(strcmp(curOperation,"ADD")==0){*p1 = (*p1) + (*p2);}
                else if(strcmp(curOperation,"SUB")==0){*p1 = (*p1) - (*p2);}
                else if(strcmp(curOperation,"MUL")==0){*p1 = (*p1) * (*p2);}
                else if(strcmp(curOperation,"DIV")==0){*p1 = (*p1) / (*p2);}
                else if(strcmp(curOperation,"MOD")==0){*p1 = (*p1) % (*p2);}
                else if(strcmp(curOperation,"AND")==0){*p1 = (*p1) & (*p2);}
                else if(strcmp(curOperation,"OR")==0){*p1 = (*p1) | (*p2);}
                else if(strcmp(curOperation,"XOR")==0){*p1 = (*p1) ^ (*p2);}
            }
            else{//未读入reg3
                int* p1, *p2, *p3;//寄存器的地址
                p1 = getRegister(reg1, r);
                p2 = getRegister(reg2, r);
                p3 = getRegister(reg3, r);
                if(strcmp(curOperation,"ADD")==0){*p1 = (*p2) + (*p3);}
                else if(strcmp(curOperation,"SUB")==0){*p1 = (*p2) - (*p3);}
                else if(strcmp(curOperation,"MUL")==0){*p1 = (*p3) * (*p3);}
                else if(strcmp(curOperation,"DIV")==0){*p1 = (*p2) / (*p3);}
                else if(strcmp(curOperation,"MOD")==0){*p1 = (*p2) % (*p3);}
                else if(strcmp(curOperation,"AND")==0){*p1 = (*p2) & (*p3);}
                else if(strcmp(curOperation,"OR")==0){*p1 = (*p2) | (*p3);}
                else if(strcmp(curOperation,"XOR")==0){*p1 = (*p2) ^ (*p3);}
            }
        }
    }
    return 0;
}
