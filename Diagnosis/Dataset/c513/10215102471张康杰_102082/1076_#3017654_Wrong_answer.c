#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define outer 0
#define brace 3
#define brack 2
#define paren 1
#define filled_brack 4
#define filled_brace 5
#define filled_paren 6

int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        int end = 0;
        char input[101];
        scanf("%s",input);
        int len = strlen(input),status[100] = {outer},top = 0;
        for(int j = 0;j < len;j++)
        {
            if(end == 1)
                break;
            switch(input[j])
            {
                case '{':
                    if(status[top] == outer || status[top] == paren)
                    {
                        top++;
                        status[top] = brace;
                    }
                    else
                    {
                        printf("No\n");
                        end = 1;
                    }
                    break;
                case '[':
                    if(status[top] == brace || status[top] == outer)
                    {
                        top++;
                        status[top] = brack;
                    }
                    else
                    {
                        printf("No\n");
                        end = 1;
                    }
                    break;
                case '(':
                    if(status[top] == brack || status[top] == outer)
                    {
                        top++;
                        status[top] = paren;
                    }
                    else
                    {
                        printf("No\n");
                        end = 1;
                    }
                    break;
                case ')':
                    if(status[top] == paren)
                    {
                        top--;
                        if(status[top] == 0)
                        {
                            break;
                        }
                        status[top] = filled_brack;
                    }
                    else
                    {
                        printf("No\n");
                        end = 1;
                    }
                    break;
                case ']':
                    if(status[top] == filled_brack)
                    {
                        top--;
                        if(status[top] == 0)
                        {
                            break;
                        }
                        status[top] = filled_brace;
                    }
                    else
                    {
                        printf("No\n");
                        end = 1;
                    }
                    break;
                case '}':
                    if(status[top] == filled_brace)
                    {
                        top--;
                        if(status[top] == 0)
                        {
                            break;
                        }
                        status[top] = paren;
                    }
                    break;
            }
            if(status[top] == 0)
            {
                printf("Yes\n");
                break;
            }
        }
    }
    return 0;    
}