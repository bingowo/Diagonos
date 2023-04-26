#include<stdio.h>
#include<string.h>
#define MAXN 101
#define out 1//外层
#define xiao 2//小括号
#define zhong 3//中括号
#define da 4//大括号
#define fillzhong 5//中括号填充版
#define fillda 6//大括号填充版

int judge(char* s)
{
    int len=strlen(s);
    int top=0;
    int state[MAXN]={0};
    state[top]=out;
    for(int i=0;i<len;i++)
    {
        int sta=state[top];
        char c=s[i];
        if(sta==out)
        {
            if(c=='(') {state[++top]=xiao;continue;}
            if(c=='[') {state[++top]=zhong;continue;}
            if(c=='{') {state[++top]=da;continue;}
            else
            {
                return 0;
            }
        }
        if(sta==xiao)
        {
            if(c=='{') {state[++top]=da;continue;}
            if(c==')')
            {
                top--;
                if(state[top]==out) continue;
                state[top]=fillzhong;
                continue;
            }
            else
            {
                return 0;
            }
        }
        if(sta==zhong||sta==fillzhong)
        {
            if(c=='(') {state[++top]=xiao;continue;}
            if(c==']')
            {
                if(sta==zhong) return 0;
                top--;
                if(state[top]==out) continue;
                state[top]=fillda;
                continue;
            }
            else
            {
                return 0;
            }
        }
        if(sta==da||sta==fillda)
        {
            if(c=='[') {state[++top]=zhong;continue;}
            if(c=='}')
            {
                if(sta==da) return 0;
                top--;
                continue;
            }
            else
            {
                return 0;
            }
        }
    }
    return state[top]==out;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        char s[MAXN];
        scanf("%s",s);
        int ans=judge(s);
        if(ans) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
