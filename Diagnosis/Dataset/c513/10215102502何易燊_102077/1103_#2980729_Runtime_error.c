#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int reg[4] = {};
    char *s = (char*)malloc(50);
    while (gets(s)!=NULL)
    {
        int temp;
        char cmd[5] = {};
        sscanf(s,"%s",cmd);
        s = strchr(s,' ')+1;
        int a,b;
        a = *s-'A';
        if (!strcmp(cmd,"OUT")) {printf("%d\n",reg[a]);continue;}
        s += 3;
        if (isalpha(*s)) temp = reg[*s-'A'];
        else temp = atoi(s);
        if (!strcmp(cmd,"IN")) reg[a] = temp;
        else if (!strcmp(cmd,"MOV")) reg[a] = temp;
        else if (!strcmp(cmd,"ADD")) reg[a] += temp;
        else if (!strcmp(cmd,"SUB")) reg[a] -= temp;
        else if (!strcmp(cmd,"MUL")) reg[a] *= temp;
        else if (!strcmp(cmd,"DIV")) reg[a] /= temp;
    }
    system("pause");
    return 0;
}