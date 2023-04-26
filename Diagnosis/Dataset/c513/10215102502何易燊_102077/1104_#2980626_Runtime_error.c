#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char *s = (char*)malloc(50);
    int reg[30] = {};
    char cmd[4];
    while (gets(s)!=NULL)
    {
        int a,b,c;
        int temp;
        sscanf(s,"%s",cmd);
        s = strchr(s,' ')+1;
        a = *s-'A';
        if (!strcmp(cmd,"OUT"))
        {
            printf("%d\n",reg[a]);
            continue;
        }
        s += 3;
        if (!strchr(s,','))
        {
            b = a;
            if (isalpha(*s)) temp = reg[*s-'A'];
            else temp = atoi(s);
        } 
        else
        {
            b = *s-'A';
            s += 3;
            c = *s-'A';
            temp = reg[c];
        }
        if (!strcmp(cmd,"IN")) reg[a] = temp;
        else if (!strcmp(cmd,"MOV")) reg[a] = reg[c];
        else if (!strcmp(cmd,"XCHG")) {reg[a]^=reg[c]; reg[c]^=reg[a]; reg[a]^=reg[c];}
        else if (!strcmp(cmd,"ADD")) reg[a] = reg[b]+temp;
        else if (!strcmp(cmd,"SUB")) reg[a] = reg[b]-temp;
        else if (!strcmp(cmd,"MUL")) reg[a] = reg[b]*temp;
        else if (!strcmp(cmd,"DIV")) reg[a] = reg[b]/temp;
        else if (!strcmp(cmd,"MOD")) reg[a] = reg[b]%temp;
        else if (!strcmp(cmd,"AND")) reg[a] = reg[b]&temp;
        else if (!strcmp(cmd,"OR"))  reg[a] = reg[b]|temp;
        else if (!strcmp(cmd,"XOR")) reg[a] = reg[b]^temp;
    }
    system("pause");
    return 0;
}