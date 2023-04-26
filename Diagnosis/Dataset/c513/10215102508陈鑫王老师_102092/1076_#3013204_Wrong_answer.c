#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int stack[110];
int sp=-1;
void push(int c)
{
    sp++;
    stack[sp]=c;
}
int top(void)
{
    return stack[sp];
}
int pop(void)
{
    return stack[sp--];
}
int isEmpty()
{
    if(sp==-1)return 1;
    else return 0;
}
void cle(void)
{
    sp=-1;
    memset(stack,0,sizeof(int)*110);
}
int main()
{
    int t;
    scanf("%d",&t);
    char c=getchar();
    for(int i=0;i<t;i++)
    {
        while((c=getchar())!='\n')
        {
            if(c=='(')
            {
                if(!isEmpty())
                {
                    if(top()!='[')
                    {
                        printf("No\n");
                        break;
                    }
                }
                push(c);
            }
            else if(c=='[')
            {
               if(!isEmpty())
                {
                    if(top()!='{')
                    {
                        printf("No\n");
                        break;
                    }
                }
                push(c);
            }
            else if(c=='{')
            {
               if(!isEmpty())
                {
                    if(top()!='(')
                    {
                        printf("No\n");
                        break;
                    }
                }
                push(c);
            }
            else if(c==')')
            {
               if(isEmpty())
               {
                   printf("No\n");
                   break;
               }
               else
               {
                   int n=pop();
                   if(n!='(')
                   {
                       printf("No\n");
                       break;
                   }
               }
            }
             else if(c==']')
            {
               if(isEmpty())
               {
                   printf("No\n");
                   break;
               }
               else
               {
                   int n=pop();
                   if(n!='[')
                   {
                       printf("No\n");
                       break;
                   }
               }
            }
             else if(c=='}')
            {
               if(isEmpty())
               {
                   printf("No\n");
                   break;
               }
               else
               {
                   int n=pop();
                   if(n!='{')
                   {
                       printf("No\n");
                       break;
                   }
               }
               }

        }
        if(isEmpty())printf("Yes\n");
        else printf("No\n");
        cle();
    }
    return 0;
}
