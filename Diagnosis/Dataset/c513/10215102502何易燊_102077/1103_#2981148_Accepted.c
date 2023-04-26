#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    long long reg[4] = {};
    char cmd[5] = {}; char s[100] = {};
    while (scanf("%s %s",cmd,s)!=EOF)
    {
        int temp;
        int p = 0;
        int a,b;
        a = s[p]-'A';
        if (!strcmp(cmd,"OUT")) {printf("%lld\n",reg[a]);continue;}
        p += 3;
        if (isalpha(s[p])) temp = reg[s[p]-'A'];
        else
        {
            char t[20] = {};
            for (int i=0;s[i+p];i++) t[i] = s[i+p];
            temp = atoll(t);
        }
        if (!strcmp(cmd,"IN")) reg[a] = temp;
        else if (!strcmp(cmd,"MOV")) reg[a] = temp;
        else if (!strcmp(cmd,"ADD")) reg[a] += temp;
        else if (!strcmp(cmd,"SUB")) reg[a] -= temp;
        else if (!strcmp(cmd,"MUL")) reg[a] *= temp;
        else if (!strcmp(cmd,"DIV")) reg[a] /= temp;
    }
    return 0;
}