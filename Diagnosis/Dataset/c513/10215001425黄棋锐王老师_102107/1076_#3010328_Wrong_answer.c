#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
struct Parenthesis
{
    char paren[MAX];
    int top;
};

int main()
{
    struct Parenthesis str;
    scanf("%s",str.paren);
    str.top = strlen(str.paren) - 1;
    char tmp[MAX];
    int i=0;
    while(str.top != -1)
    {
        tmp[i] = str.paren[str.top];
        switch(tmp[i])
        {
        case '(':
            if (tmp[i-1]==')') i-=2;break;
        case '[':
            if(tmp[i-1]==']') i-=2;break;
        case '{':
            if(tmp[i-1]=='}') i-=2;break;
        }
        i++;
        str.top--;
    }
    if (i)
        printf("No\n");
    else
        printf("Yes\n");
    return 0;
}
