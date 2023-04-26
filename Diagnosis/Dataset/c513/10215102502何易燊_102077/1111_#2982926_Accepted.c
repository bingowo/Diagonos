#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int graph[50][50];
int c[5] = {};

void init()
{
    for (int i=0;i<=4;i++) c[i] = 0;
    for (int i=1;i<=41;i++)
        for (int j=1;j<=41;j++) graph[i][j] = '.';
    for (int i=1;i<=41;i++) graph[21][i] = '-';
    for (int i=1;i<=41;i++) graph[i][21] = '|';
    graph[21][21] = '+'; graph[1][21] = '^'; graph[21][41] = '>';
}

int fun(int c3,int c2,int c1,int c0,int x)
    {return c3*x*x*x+c2*x*x+c1*x+c0;}

int main()
{
    char s[1001] = {};
    while (scanf("%s",s)!=EOF)
    {
        init();
        s[strlen(s)] = '+';
        char *t = &s[5];
        char buf[101] = {}; int p = 0;
        int state = 1;
        int index = 0;
        for (int i=0;t[i];i++)
        {
            if (state)
            {
                if ((t[i]=='+'||t[i]=='-'))
                {
                    if (!buf[0]) buf[p++] = t[i];
                    else state = 0;
                }
                else if (t[i]!='x') buf[p++] = t[i];
                else {state = 0; index = 1;}
            }
            else
            {
                if (isdigit(t[i])) index = t[i]-'0';
            }
            if (!state&&(t[i]=='+'||t[i]=='-')&&i!=0)
            {
                if (!strcmp(buf,"-")) c[index] = -1;
                else if (!strcmp(buf,"+")||!buf[0]) c[index] = 1;
                else c[index] = atoi(buf);
                index = 0; state = 1;
                memset(buf,0,sizeof(buf)); p = 0;
                buf[p++] = t[i];
            }
        }
        memset(s,0,sizeof(s));
        for (int i=-20;i<=20;i++)
        {
            int value = fun(c[3],c[2],c[1],c[0],i);
            if (abs(value)<=20) graph[21-value][i+21] = '*';
        }
        for (int i=1;i<=41;i++)
        {
            for (int j=1;j<=41;j++) printf("%c",graph[i][j]);
            printf("\n");
        }
        printf("\n");
    }
    system("pause");
    return 0;
}