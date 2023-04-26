#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define outer 0
#define paren 1
#define brack 2
#define brace 3
#define filled_brack 4
#define filled_brace 5
int judge(char *str)
{
    int len = strlen(str);
    int states[6],top=0;
    states[top] = outer;
    int i=0;
    for(i=0;i<len;i++)
    {
        int state = states[top];
        char ch = str[i];
        if(state == outer)
        {
            if(ch == '(')
            {
                states[++top] = paren;
                continue;
            }
            if(ch == '[')
            {
                states[++top] = brack;
                continue;
            }
            if(ch == '{')
                {
                    states[++top] = brace;
                    continue;
                }
            else return 0;
        }
        if(state == paren)
        {
            if(ch == '{')
            {
                states[++top] = brace;
                continue;
            }
            if(ch == ')')
            {
                top--;
                if(states[top] == outer)
                    continue;
                states[top] = filled_brack;
                continue;
            }
            else return 0;
        }

        if(state == brack || state == filled_brack)
        {
            if(ch == '(')
            {
                states[++top] = paren;
                continue;
            }
            if(ch == ']')
            {
                top--;
                if(states[top] == outer) continue;
                states[top] = filled_brace;
                continue;
            }
            else return 0;
        }
        if(state == brace || state == filled_brace)
        {
            if(ch == '[')
            {
                states[++top] = brack;
                continue;
            }
            if(ch == '}')
            {
                if(states[top] == brace)
                    return 0;
                top--;
                continue;
            }
            else return 0;
        }
    }
    return states[top] == outer;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        char str[101]={0};
        scanf("%s",str);
        printf(judge(str)? "Yes\n":"No\n");
    }
    return 0;
}
