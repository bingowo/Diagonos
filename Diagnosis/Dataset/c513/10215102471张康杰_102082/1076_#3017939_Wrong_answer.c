//优雅的括号序列
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define outer 0
#define brace 3
#define brack 2
#define paren 1
#define filled_brack 4
#define filled_brace 5

int judge(char a[])
{
    int len = strlen(a),states[101],top = 0;
    states[top] = outer;
    for(int i = 0;i < len;i++)
    {
        switch(states[top])
        {
            case outer:
            if(a[i] == '{')
                states[++top] = brace;
            else if(a[i] == '[')
                states[++top] = brack;
            else if(a[i] == '(')
                states[++top] = paren;
            else
                return 0;
            break;
            case paren:
            if(a[i] == '{')
                states[++top] = brace;
            else if(a[i] == ')')
            {
                top--;
                if(states[top] != outer)
                    states[top] = filled_brack;
            }
            else
                return 0;
            break;
            case filled_brack:
            case brack:
            if(a[i] == '(')
                states[++top] = brace;
            else if(a[i] == ']')
            {
                if(states[top] == brack)
                    return 0;
                top--;
                if(states[top] != outer)
                    states[top] = filled_brace;
            }
            else
                return 0;
            break;
            case filled_brace:
            case brace:
            if(a[i] == '[')
                states[++top] = brack;
            else if(a[i] == '}')
            {
                if(states[top] == brace)
                    return 0;
                top--;
            }
            else
                return 0;
            break;
        }
    }
    if(states[top] == outer)
        return 0;
}

int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        char input[101];
        scanf("%s",input);
        printf(judge(input)?"Yes\n":"No\n");
    }
    return 0;
}