#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int reg[26] = {};
    char cmd[5], s[100];
    while (scanf("%s %s",cmd,s)!=EOF)
    {
        int a,b,c;
        int temp, p = 0;
        a = s[p]-'A';
        if (!strcmp(cmd,"OUT"))
        {
            printf("%d\n",reg[a]);
            continue;
        }
        p += 3;
        if (!strchr(&s[p],','))
        {
            b = a;
            if (isalpha(s[p])) c = s[p]-'A';
            else temp = atoi(&s[p]);
        } 
        else
        {
            b = s[p]-'A';
            p += 3;
            c = s[p]-'A';
            if (isalpha(s[p])) temp = reg[c];
            else temp = atoi(&s[p]);
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
    return 0;
}