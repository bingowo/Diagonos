#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char stack_alp[501] = {'\0'};
    int stack_dig[501] = {0};
    char s[51];
    scanf("%s",s);
    int top_alp = -1,len = strlen(s),i,top_dig = -1;
    for(i = 0;i < len;i++)
    {
        if(s[i] == '(')
            stack_alp[++top_alp] = s[i];
        else if(s[i] == ')' && stack_alp[top_alp] == '(' && stack_dig[top_dig] != 0)
        {
            stack_dig[top_dig] *= 2;
            stack_alp[top_alp] = '\0';
            top_alp--;
        }
        else if(s[i] == ')' && stack_alp[top_alp] == '(')
        {
            stack_dig[++top_dig] = 1;
            stack_alp[top_alp--] = '\0';
        }
        else if(stack_dig[top_dig] != 0 && stack_dig[top_dig - 1] != 0 && top_dig >= 1)
        {
            stack_dig[top_dig - 1] = stack_dig[top_dig] + stack_dig[top_dig - 1];
            stack_dig[top_dig] = 0;
            top_dig--;
        }
    }
    int point = 0;
    for(i = 0;i <= top_dig;i++)
    {
        point += stack_dig[i];
    }
    printf("%d",point);
    return 0;
}
