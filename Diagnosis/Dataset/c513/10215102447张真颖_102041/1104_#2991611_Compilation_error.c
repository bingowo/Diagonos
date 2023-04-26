#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int judge(char s[])
{
    if(s[0]=='I') return 0;
    else if(s[0]=='O'&&s[1]=='U') return 1;
    else if(s[0]=='M'&&s[2]=='V') return 2;
    else if(s[0]=='X'&&s[1]=='C') return 3;
    else if(s[0]=='A'&&s[1]=='D') return 4;
    else if(s[0]=='S') return 5;
    else if(s[0]=='M'&&s[1]=='U') return 6;
    else if(s[0]=='D') return 7;
    else if(s[0]=='M'&&s[2]=='D') return 8;
    else if(s[0]=='A'&&s[1]=='N') return 9;
    else if(s[0]=='O'&&s[1]=='R') return 10;
    else if(s[0]=='X'&&s[1]=='O') return 11;
}
int f(int a,int b,int c)
{
    switch(c)
    {
    case 4:
        return a+b;
    case 5:
        return a-b;
    case 6:
        return a*b;
    case 7:
        return a/b;
    case 8:
        return a%b;
    case 9:
        return a&b;
    case 10:
        return a|b;
    case 11:
        return a^b;
    }
}

int main()
{
    int operands[26]={0};
    char s[13]={0};
    while(gets(s)!=EOF)
    {
        int comma=0;
        for(int i=0;s[i];i++)
            if(s[i]==',') s[i]=' ',comma+=1;
        char op[4]={0},op1[4]={0},op2[4]={0},op3[4]={0},op4[4]={0};
        sscanf(s,"%s",op);
        switch(judge(op))
        {
        case 0:
            {
                int d=0;
                sscanf(s,"%s%s%d",op,op1,&d);
                operands[op1[0]-'A']=d;
                break;
            }
        case 1:
            {
                sscanf(s,"%s%s",op,op1);
                printf("%d\n",operands[op1[0]-'A']);
                break;
            }
        case 2:
            {
                char op2[4]={0};
                sscanf(s,"%s%s%s",op,op1,op2);
                operands[op1[0]-'A']=operands[op2[0]-'A'];
                break;
            }
        case 3:
            {
                sscanf(s,"%s%s%s",op,op1,op2);
                int t=operands[op1[0]-'A'];
                operands[op1[0]-'A']=operands[op2[0]-'A'];
                operands[op2[0]-'A']=t;
                break;
            }
        case 4:case 5:case 6:case 7:case 8:case 9:case 10:case 11:
            {
                if(comma==2)
                {
                    sscanf(s,"%s%s%s%s",op,op1,op2,op3);
                    operands[op1[0]-'A']=f(operands[op2[0]-'A'],operands[op3[0]-'A'],judge(op));
                }
                else
                {
                    sscanf(s,"%s%s%s",op,op1,op2);
                    operands[op1[0]-'A']=f(operands[op1[0]-'A'],operands[op2[0]-'A'],judge(op));
                }
                break；
            }
        }
    }
    return 0;
}