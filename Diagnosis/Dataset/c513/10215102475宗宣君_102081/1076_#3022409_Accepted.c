#include <stdio.h>
#include <string.h>
#define outer 0//外层状态
#define paren 1//小括号状态
#define brack 2//中括号状态
#define brace 3//大括号状态
#define filled_brack 4//表示中括号内填充（）
#define filled_brace 5//表示大括号内填充[]
int judge(char *s)
{
    int len = strlen(s),top = 0,i,states[1000] = {outer};
    for(i = 0;i<len;i++)
    {
        int state = states[top];
        char ch= s[i];
        switch(state)
        {
        case outer:
            if(ch=='(') states[++top]=paren;
            else if(ch=='[') states[++top] = brack;
            else if(ch=='{') states[++top] = brace;
            else return 0;
            break;
        case paren:
            if(ch=='{') states[++top] = brace;
            else if(ch==')')
            {
                top--;
                if(states[top]!=outer)
                    states[top] = filled_brack;
            }
            else return 0;
            break;
        case brack:
        case filled_brack:
            if(ch=='(') states[++top] = paren;
            else if(ch==']')
            {
                if(state==brack) return 0;
                top--;
                if(states[top]!=outer)
                    states[top] = filled_brace;
            }
            else return 0;
            break;
        case brace:
        case filled_brace:
            if(ch=='[') states[++top] = brack;
            else if(ch=='}')
            {
                if(state==brace) return 0;
                top--;
            }
            else return 0;
            break;
        }
    }
    return states[top]==outer;
}
int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i<T;i++)
    {
        char s[101];
        int s0 = 0;
        scanf("%s",s);
        printf(judge(s)?"Yes\n":"No\n");
    }
    return 0;
}
