#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 #define outer 0 //外层状态
 #define paren 1 //小括号状态
 #define brack 2 //中括号状态
 #define brace 3 //大括号状态
 #define filled_brack 4 //中括号内填充小括号
 #define filled_brace 5 //大括号内填充中括号
 #define MAXN 105
 int judge(char *str)
 {
     int len=strlen(str),states[MAXN],top=0;
     states[top]=outer;
     for(int i=0;i<len;i++)
     {
         int state=states[top];
         char ch=str[i];
         switch(state)
         {
         case outer:
            if(ch=='(') states[++top]=paren;
            else if(ch=='[') states[++top]=brack;
            else if(ch=='{') states[++top]=brace;
            else return 0;
            break;
         case paren:
            if(ch=='{') states[++top]=brace;
            else if(ch==')')
            {
                top--;
                if(states[top]!=outer) states[top]=filled_brack;
            }
            else return 0;
            break;
         case brack:
            if(ch=='(') states[++top]=paren;
            else return 0;
            break;
         case brace:
            if(ch=='[') states[++top]=brack;
            else return 0;
            break;
         case filled_brace:
            if(ch=='[') states[++top]=brack;
            else if(ch=='}')
            {
                if(state==brace) return 0;
                top--;
            }
            else return 0;
            break;
        case filled_brack:
            if(ch=='(') states[++top]=paren;
            else if(ch==']')
            {
                if(state==brack) return 0;
                top--;
                if(states[top]!=outer) states[top]=filled_brace;
            }
            else return 0;
            break;
         }
     }
     return states[top]==outer;
 }
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        char str[101]={0};
        scanf("%s",str);
        printf(judge(str)?"Yes\n":"No\n");
    }
    return 0;
}
