#include <stdio.h>
#include <string.h>
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int ret,res = 1;
        char s[111];scanf("%s",s);
        if(s[0]=='{') ret = 3;
        if(s[0]=='[') ret = 2;
        if(s[0]=='(') ret = 1;
        int depth = 1;
        for(int i = 1; i< strlen(s); i++)
        {
            if(!depth) {
                if(s[i]=='{') ret = 3;
                else if(s[i]=='[') ret = 2;
                else if(s[i]=='(') ret = 1;
                depth = 1;
                continue;
            }
            if(s[i]=='{'&&ret == 1) {ret = 3; depth++;}
            else if(s[i]=='[' && ret == 3) {ret = 2; depth++;}
            else if(s[i]=='(' && ret == 2) {ret = 1; depth++;}
            else if(s[i]=='}' && (ret == 2||ret == 3)) {ret = 1; depth--;}
            else if(s[i]==']' && (ret == 1||ret == 2)) {ret = 3; depth--;}
            else if(s[i]==')' && (ret == 3||ret == 1)) {ret = 2; depth--;}
            else {printf("No\n");
//                printf("%c",s[i]);
                res = 0;break;}
        }
        if(res) printf("Yes\n");
    }
    return 0;
}