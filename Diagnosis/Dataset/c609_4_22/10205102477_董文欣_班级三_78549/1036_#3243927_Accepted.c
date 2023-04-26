#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[51];
    scanf("%s",s);
    int len  = strlen(s);
    int stk[len+1], top = 0;
    stk[top++] = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') stk[top++] = 0;
        else {
            int res = stk[top - 1];
            top--;
            int t = 2*res > 1 ? 2*res : 1;
            stk[top - 1] += t;
        }
    }
    printf("%d",stk[top - 1]);
    return 0;
}
