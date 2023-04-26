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
            case MOV:
                storage[code[0]]=storage[code[3]];
                break;
            case ADD:
                storage[code[0]]=storage[code[0]]+storage[code[3]];
                break;
            case SUB:
                storage[code[0]]=storage[code[0]]-storage[code[3]];
                break;
            case MUL:
                storage[code[0]]=storage[code[0]]*storage[code[3]];
                break;
            case DIV:
                storage[code[0]]=storage[code[0]]/storage[code[3]];
                break;
            case OUT:
                printf("%d\n",storage[code[0]]);
            default:
                break;
        }
    }
    return 0;
}