#include <stdio.h>
#include <string.h>

int main()
{
    char cmd[5];
    char s[20];

    int data;
    char reg1[5],reg2[5];
    int registers[4]={0};
    while(~scanf("%s",cmd))
    {
        scanf("%s",s);
        for(int i=0;s[i];i++) {
            if (s[i] == ',')
                s[i] = ' ';
        }//用空格替换逗号
        switch (cmd[0]) {
            case 'I':
                sscanf(s,"%s%d",reg1,&data);
                registers[reg1[0]-'A']=data;
                break;
            case 'O':
                sscanf(s,"%s",reg1);
                printf("%d\n",registers[reg1[0]-'A']);
                break;
            case 'A':
                sscanf(s,"%s%s",reg1,reg2);
                registers[reg1[0]-'A']=registers[reg1[0]-'A']+registers[reg2[0]-'A'];
                break;
            case 'S':
                sscanf(s,"%s%s",reg1,reg2);
                registers[reg1[0]-'A']=registers[reg1[0]-'A']-registers[reg2[0]-'A'];
                break;
            case 'D':
                sscanf(s,"%s%s",reg1,reg2);
                registers[reg1[0]-'A']=registers[reg1[0]-'A']/registers[reg2[0]-'A'];
                break;
            case 'M':
                sscanf(s,"%s%s",reg1,reg2);
                if(!strcmp(cmd,"MOV"))
                    registers[reg1[0]-'A']=registers[reg2[0]-'A'];
                else if(!strcmp(cmd,"MUL"))
                    registers[reg1[0]-'A']=registers[reg1[0]-'A']*registers[reg2[0]-'A'];
                break;
        }
    }

}