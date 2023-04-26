#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define outer 0 //外层状态
#define paren 1 //小括号状态
#define brack 2 //中括号状态
#define brace 3 //大括号状态
#define MAXN 100
int judge(char* str) 
{
    int len = strlen(str), states[MAXN], top = 0;
    states[top] = outer;
    for (int i = 0; i < len; i++) 
    {
        int state = states[top];
        char ch = str[i];
        if (state == outer) 
        {
            if (ch == '(') {states[++top] = paren; continue;}
            if (ch == '[') {states[++top] = brack; continue;}
            if (ch == '{') {states[++top] = brace; continue;}
            else return 0;
        }
        if (state == paren) 
        {
            if (ch == '{') {states[++top] = brace; continue;}
            if (ch == ')') {top--; continue;}
            else return 0;
        }
        if (state == brack) 
        {
            if (ch =='(') {states[++top] = paren; continue;}
            if (ch == ']') {top--; continue;}
            else return 0;
        }
        if (state == brace) 
        {
            if (ch == '[') {states[++top] = brack; continue;}
            if (ch == '}') {top--; continue;}
            else return 0;
        }
    }
    return states[top] == outer;
}
int main() 
{
    int T;
    scanf("%d", &T);
    while (T--) 
    {
        char str[101] = {0};
        scanf("%s", str);
        printf(judge(str)? "Yes\n": "No\n");
    }
    return 0;
}