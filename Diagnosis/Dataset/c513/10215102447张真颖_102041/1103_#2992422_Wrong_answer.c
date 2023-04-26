#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int judge(char s[])
{
    if(s[0]=='I') return 0;
    else if(s[0]=='M'&&s[1]=='O') return 1;
    else if(s[0]=='A') return 2;
    else if(s[0]=='S') return 3;
    else if(s[0]=='M'&&s[1]=='U') return 4;
    else if(s[0]=='D') return 5;
    else if(s[0]=='O') return 6;
}
int f(int a,int b,int c)
{
    switch(c)
    {
    case 1:
        return b;
    case 2:
        return a+b;
    case 3:
        return a-b;
    case 4:
        return a*b;
    case 5:
        return a/b;
    }
}

int main()
{
    char s[500020]={0};
    int re[4]={0};
    while(gets(s)!=NULL)
    {
        char op[4]={0},op1[3]={0},op2[3]={0};
        for(int i=0;i<strlen(s);i++)
            if(s[i]==',') s[i]=' ';
        sscanf(s,"%s",op);
        switch(judge(op))
        {
        case 0:
            {
                int d=0;
                sscanf(s,"%s%s%d",op,op1,&d);
                re[op1[0]-'A']=d;
                break;
            }
        case 1:case 2:case 3:case 4:case 5:
            {
                sscanf(s,"%s%s%s",op,op1,op2);
                re[op1[0]-'A']=f(re[op1[0]-'A'],re[op2[0]-'A'],judge(op));
                break;
            }
        case 6:
            {
                sscanf(s,"%s%s",op,op1);
                printf("%d",re[op1[0]-'A']);
                break;
            }

        }
    }
    return 0;
}