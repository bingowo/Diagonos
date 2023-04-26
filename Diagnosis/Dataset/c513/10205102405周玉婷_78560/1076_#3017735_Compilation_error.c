#include <stdio.h>
#include <string.h>
//有限自动机解决

#define outer 0 //外层状态
#define paren 1 //小括号状态
#define brack 2 //中括号状态
#define brace 3 //大括号状态
#define filled_brack 4 //已填充（）状态
#define filled_brace 5 //已填充[]状态
#define MAXN 10000
int judge( char *s)
{
   int len = strlen(s);
   int stack[MAXN]={0}, top=0, stack[0] = outer; //存放状态的栈的建立
   int state;
   for(int i=0; i<len; i++)
   {
      state = stack[top];
      char ch = s[i];
      switch(state)
      {
          case outer:
          if(ch == '(')  stack[++top] = paren;
          else if(ch == '[')  stack[++top] = brack;
          else if(ch == '{')  stack[++top] = brace;
          else return 0;
          break;

          case paren:
          if(ch == ')') 
          {top--;
          if(stack[top] == brack) stack[top] = filled_brack;}
          else if(ch == '{')  stack[++top] = brace;
          else return 0;
          break;

          case brack:
          if(ch == '(') stack[++top] = paren;
          else return 0;
          break;

          case brace:
          if(ch == '[') stack[++top] = brack;
          else return 0;
          break;

          case filled_brack:
          if(ch == ']') 
          { top--; if(stack[top] == brace)  stack[top] = filled_brace; }
          else return 0;
          break;

          case filled_brace:
          if(ch == '}') top--;
          else return 0;
          break;
      }
   }
   return 1;
}


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char s[101] = {0};
        scanf("%s",s);
        printf(judge(s)?"Yes\n":"No\n");
    }
    return 0;
}