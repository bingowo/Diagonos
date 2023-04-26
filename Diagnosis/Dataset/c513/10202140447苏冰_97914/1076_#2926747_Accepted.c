#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
char stack[110];
int main()
{
    int T;
    scanf("%d",&T);
    char s[110];
    for(int cas=0;cas<T;cas++)
    {
        scanf("%s",s);
        int flag=1;
        int top=-1;
        for(int i=0;i<strlen(s);i++)
        {
            switch(s[i])
            {
                case('{'):case('['):case('('):stack[++top]=s[i];break;
                case('}'):  if(top==-1) flag=0;
                            else if(stack[top]=='{')
                            {
                                if(top!=0 && stack[top-1]!='(') flag=0;
                                else top--;
                            }
                            else flag=0;
                            break;
                case(']'):  if(top==-1) flag=0;
                            else if(stack[top]=='[')
                            {
                                if(top!=0 && stack[top-1]!='{') flag=0;
                                else top--;
                            }
                            else flag=0;
                            break;
                 case(')'): if(top==-1) flag=0;
                            else if(stack[top]=='(')
                            {
                                if(top!=0 && stack[top-1]!='[') flag=0;
                                else top--;
                            }
                            else flag=0;
                            break;
            }
            if(flag==0) break;
        }
        if(top==-1 && flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
