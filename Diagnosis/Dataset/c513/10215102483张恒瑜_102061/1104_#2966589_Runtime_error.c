#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define IN 0
#define MOV 1
#define ADD 2
#define SUB 3
#define MUL 4
#define DIV 5
#define OUT 6
#define XCHG 7
#define MOD 8
#define AND 9
#define OR 10
#define XOR 11
int storage[128]={0};

int cmdcmp(const char* cmd)
{
    if(!strcmp(cmd,"IN")) return IN;
    else if(!strcmp(cmd,"MOV")) return MOV;
    else if(!strcmp(cmd,"ADD")) return ADD;
    else if(!strcmp(cmd,"SUB")) return SUB;
    else if(!strcmp(cmd,"MUL")) return MUL;
    else if(!strcmp(cmd,"DIV")) return DIV;
    else if(!strcmp(cmd,"OUT")) return OUT;
    else if(!strcmp(cmd,"XCHG")) return XCHG;
    else if(!strcmp(cmd,"MOD")) return MOD;
    else if(!strcmp(cmd,"AND")) return AND;
    else if(!strcmp(cmd,"OR")) return OR;
    else if(!strcmp(cmd,"XOR")) return XOR;
    else return EOF;
}

int main()
{
    char cmd[10]={'\0'};
    while (scanf("%s",cmd)!=EOF)
    {
        char code[100]={'\0'};
        scanf("%s",code);
        switch (cmdcmp(cmd))
        {
            case IN:
                {
                    char num[20]={'\0'};
                    for(int i=3;i<strlen(code);i++) num[i-3]=code[i];
                    storage[code[0]]=atoi(num);
                    break;
                }
            case XCHG:
                {
                    int tmp=storage[code[0]];
                    storage[code[0]]=storage[code[3]];
                    storage[code[3]]=tmp;
                }
            case MOV:
                storage[code[0]]=storage[code[3]];
                break;
            case ADD:
                if(strlen(code)==5) storage[code[0]]=storage[code[0]]+storage[code[3]];
                else storage[code[0]]=storage[code[3]]+storage[code[6]];
                break;
            case SUB:
                if(strlen(code)==5) storage[code[0]]=storage[code[0]]-storage[code[3]];
                else storage[code[0]]=storage[code[3]]-storage[code[6]];
                break;
            case MUL:
                if(strlen(code)==5) storage[code[0]]=storage[code[0]]*storage[code[3]];
                else storage[code[0]]=storage[code[3]]*storage[code[6]];
                break;
            case DIV:
                if(strlen(code)==5) storage[code[0]]=storage[code[0]]/storage[code[3]];
                else storage[code[0]]=storage[code[3]]/storage[code[6]];
                break;
            case MOD:
                if(strlen(code)==5) storage[code[0]]=storage[code[0]]%storage[code[3]];
                else storage[code[0]]=storage[code[3]]%storage[code[6]];
                break;
            case AND:
                if(strlen(code)==5) storage[code[0]]=storage[code[0]]&storage[code[3]];
                else storage[code[0]]=storage[code[3]]&storage[code[6]];
                break;
            case OR:
                if(strlen(code)==5) storage[code[0]]=storage[code[0]]|storage[code[3]];
                else storage[code[0]]=storage[code[3]]|storage[code[6]];
                break;
            case XOR:
                if(strlen(code)==5) storage[code[0]]=storage[code[0]]^storage[code[3]];
                else storage[code[0]]=storage[code[3]]^storage[code[6]];
                break;
            case OUT:
                printf("%d\n",storage[code[0]]);
            default:
                break;
        }
    }
    return 0;
}