#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char stack[501] = {'\0'},s[51];
    scanf("%s",s);
    int top = -1,len = strlen(s),i;
    for(i = 0;i < len;i++)
    {
        if(s[i] == '(')
            stack[++top] = s[i];
        else if(s[i] == ')' && stack[top] == '(')
            stack[top] = 1 + '0';
        else if(s[i] == ')' && isdigit(stack[top]) && stack[top - 1] == '(')
        {
            stack[top - 1] = (stack[top] - '0') * 2 + '0';
            top--;
        }
        else if(s[i] == ')' && isdigit(stack[top]) && isdigit(stack[top - 1]))
        {
            int temp = 0;
            while(isdigit(stack[top]))
            {
                temp = temp + stack[top] - '0';
                top--;
            }
            stack[++top] = temp + '0';
        }
    }
    stack[++top] = ')';
    int point = 0;
    for(i = 0;stack[i] != ')';i++)
    {
        if(isdigit(stack[i]))
            point += stack[i] - '0';
    }
    printf("%d",point * 2);
    return 0;
}
