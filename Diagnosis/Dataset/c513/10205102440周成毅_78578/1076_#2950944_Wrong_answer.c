#include <stdio.h>
#include <string.h>

int judge(char a, char b)
{
    if(a=='{')
    {
        if(b=='[') return 1;
        else return 0;
    }
    else if(a=='[')
    {
        if(b=='(') return 1;
        else return 0;
    }
    else if(a=='(')
    {
        if(b=='{') return 1;
        else return 0;
    }
}

int judge1(char a, char b)
{
    if(a=='{')
    {
        if(b=='}') return 1;
        else return 0;
    }
    else if(a=='[')
    {
        if(b==']') return 1;
        else return 0;
    }
    else if(a=='(')
    {
        if( b==')') return 1;
        else return 0;
    }
}

int main() {
   int T;
   char s[101];
   char stack[101];
    scanf("%d",&T);
    for(int i=0;i<T;i++) {
        scanf("%s", s);
        int head=0;
        int flag=0;
        stack[head++]=s[0];
        int j = 1;
        unsigned len = strlen(s);
        for(;j<len;j++){
            if(head==0){
                stack[head++]=s[j];
                continue;
            } else if(judge1(stack[head-1],s[j])){
                head--;
                continue;
            } else if(judge(stack[head-1],s[j])){
                stack[head++]=s[j];
                continue;
            } else{
                printf("No\n");
                flag=1;
                break;
            }
            
        }
        if(head==0)
            printf("Yes\n");
        else if(flag==0)
            printf("No\n");
    }
    return 0;
}
