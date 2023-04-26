#include <stdio.h>
#include <string.h>

int main() {
   int T;
   char s[101];
   char stack[101];
   int flag=0;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%s",s);
        int head=0;
        unsigned len=strlen(s);
        for(int j=0;j<len;j++){
            if(s[j]=='(' && head==0 || s[j]=='(' &&stack[head-1]=='[')
                stack[head++]=s[j];
            else if(s[j]=='[' && head==0 || s[j]=='[' &&stack[head-1]=='{')
                stack[head++]=s[j];
            else if(s[j]=='{' && head==0 || s[j]=='{' &&stack[head-1]=='(')
                stack[head++]=s[j];
            else{
                if(!head || s[j]=='(' || s[j]=='[' || s[j]=='{'){
                    flag=1;
                    break;
                } else{
                    if(s[j]==')' && stack[head-1]=='(')
                        head--;
                    else if(s[j]==']' && stack[head-1]=='[')
                        head--;
                    else if(s[j]=='}' && stack[head-1]=='{')
                        head--;
                    else{
                        flag=1;
                        break;
                    }
                }
            }
        }
        if(!head && flag==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
