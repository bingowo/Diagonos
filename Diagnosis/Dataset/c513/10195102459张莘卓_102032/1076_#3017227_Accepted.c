#include <stdio.h>
#include <string.h>

void elegantJudge(void) {
    char s[101], stack[101]={0};
    scanf("%s",s);
    int top = -1, i = 0;
    while(i < strlen(s)) {
        if(top == -1) {
            if(s[i]=='}'||s[i]==')'||s[i]==']') break;
            stack[++top] = s[i];
        }else if(stack[top] == '{') {
            if(s[i] == '[') stack[++top] = s[i];
            else if(s[i] == '}') --top;
            else break;
        }else if(stack[top] == '[') {
            if(s[i] == '(') stack[++top] = s[i];
            else if(s[i] == ']') --top;
            else break;
        }else {
            if(s[i] == '{') stack[++top] = s[i];
            else if(s[i] == ')') --top;
            else break;
        }
        ++i;
    }
    if(top==-1 && i==strlen(s)) printf("Yes\n");
    else printf("No\n");
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0; i<T; ++i)
        elegantJudge();
    return 0;
}
