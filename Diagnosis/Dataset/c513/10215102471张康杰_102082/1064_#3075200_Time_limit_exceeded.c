#include <stdio.h>
#include <stdlib.h>
#define N 105

int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        double stack_dig[N] = {.0};
        char stack_alp[N] = {'\0'};
        int top_dig = -1,top_alp = -1;
        char s[N];
        while(scanf("%s",s))
        {
            switch(s[0])
            {
            case '+':
                stack_alp[++top_alp] = s[0];
                break;
            case '-':
                stack_alp[++top_alp] = s[0];
                break;
            case '*':
                stack_alp[++top_alp] = s[0];
                break;
            case '/':
                stack_alp[++top_alp] = s[0];
                break;
            default:
                if(top_dig >= 0)
                {
                    switch(stack_alp[top_alp])
                    {
                    case '+':
                        stack_dig[top_dig] += atof(s);
                        stack_alp[top_alp--] = '\0';
                        break;
                    case '-':
                        stack_dig[top_dig] -= atof(s);
                        stack_alp[top_alp--] = '\0';
                        break;
                    case '*':
                        stack_dig[top_dig] *= atof(s);
                        stack_alp[top_alp--] = '\0';
                        break;
                    case '/':
                        stack_dig[top_dig] /= atof(s);
                        stack_alp[top_alp--] = '\0';
                    }
                }
                else
                    stack_dig[++top_dig] = atof(s);
            }
        }
        printf("case #%d:\n%.6lf\n",i,stack_dig[top_dig]);
    }
    return 0;
}
