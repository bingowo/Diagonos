#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    long long reg[26] = {};
    char cmd[5] = {}, s[100] = {};
    while (scanf("%s %s",cmd,s)!=EOF)
    {
        int a,b,c;
        long long temp, p = 0;
        a = s[p]-'A';
        if (!strcmp(cmd,"OUT"))
        {
            printf("%lld\n",reg[a]);
            continue;
        }
        p += 3;
        if (!strchr(&s[p],','))
        {
            b = a;
            if (isalpha(s[p])) {c = s[p]-'A'; temp = reg[c];}
            else temp = atoll(&s[p]);
        } 
        else
        {
            b = s[p]-'A';
            p += 3;
            if (isalpha(s[p])) {c = s[p]-'A'; temp = reg[c];}
            else temp = atoll(&s[p]);
        }
        if (!strcmp(cmd,"IN")) reg[a] = temp;
        else if (!strcmp(cmd,"MOV")) reg[a] = reg[c];
        else if (!strcmp(cmd,"XCHG")) {temp = reg[a]; reg[a] = reg[c]; temp;}
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