#include <stdio.h>
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
    char s[101] = {};
    while (scanf("%s",s)!=EOF)
    {
        init();
        s[strlen(s)] = '+';
        char *t = &s[5];
        char buf[4] = {}; int p = 0;
        int state = 1;
        int index = 0;
        for (int i=0;t[i];i++)
        {
            if (state)
            {
                if (isdigit(t[i])) buf[p++] = t[i];
                else if (t[i]=='x') {state = 0; index = 1;}
                else state = 0;
            }
            else
            {
                if (isdigit(t[i])) index = t[i]-'0';
            }
            if (!state&&(t[i]=='+'||t[i]=='-'))
            {
                c[index] = atoi(buf);
                index = 0;
                memset(buf,0,5); p = 0;
                buf[p++] = t[i];
            }
        }
        for (int i=0;i<101;i++) s[i] = '\0';
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
    return 0;
}