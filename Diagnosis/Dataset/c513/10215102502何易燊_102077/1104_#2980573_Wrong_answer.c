#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char *s = (char*)malloc(20);
    int reg[26] = {};
    char cmd[4];
    int a,b,c;
    while (gets(s)!=NULL)
    {
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
            if (isdigit(*s)) temp = atoi(s);
            else temp = reg[*s-'A'];
        } 
        else
        {
            b = *s-'A';
            s += 3;
            temp = reg[*s-'A'];
        }
        if (!strcmp(cmd,"IN")) reg[a] = temp;
        else if (!strcmp(cmd,"MOV")) reg[a] = temp;
        else if (!strcmp(cmd,"XCHG")) {reg[a]^=temp; temp^=reg[a]; reg[a]^=temp;}
        else if (!strcmp(cmd,"ADD")) reg[a] = reg[b]+temp;
        else if (!strcmp(cmd,"SUB")) reg[a] = reg[b]-temp;
        else if (!strcmp(cmd,"MUL")) reg[a] = reg[b]*temp;
        else if (!strcmp(cmd,"DIV")) reg[a] = reg[b]/temp;
        else if (!strcmp(cmd,"MOD")) reg[a] = reg[b]%temp;
        else if (!strcmp(cmd,"AND")) reg[a] = reg[b]&temp;
        else if (!strcmp(cmd,"OR"))  reg[a] = reg[b]|temp;
        else if (!strcmp(cmd,"XOR")) reg[a] = reg[b]^temp;
    }
    return 0;
}