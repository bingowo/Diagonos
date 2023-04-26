#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        char s[101];
        scanf("%s", s);
        int len = strlen(s);

        int top = -1;
        char stack[101];
        int flag = 1;
        for (int j = 0; j < len; j++) {
            if (top == -1) {stack[++top] = s[j]; continue;}
            switch(s[j])
            {
                case '{':
                    if (stack[top] == '(') stack[++top] = s[j];
                    else {flag = 0; break;}
                    break;
                case '}':
                    if (stack[top] == '{') top--;
                    else {flag = 0; break;}
                    break;
                case '[':
                    if (stack[top] == '{') stack[++top] = s[j];
                    else {flag = 0; break;}
                    break;
                case ']':
                    if (stack[top] == '[') top--;
                    else {flag = 0; break;}
                    break;
                case '(':
                    if (stack[top] == '[') stack[++top] = s[j];
                    else {flag = 0; break;}
                    break;
                case ')':
                    if (stack[top] == '(') {top--;}
                    else {flag = 0; break;}
                    break;
            }
        }
        if (flag && top == -1) printf("Yes\n");
        else printf("No\n");
    }



    return 0;
}
