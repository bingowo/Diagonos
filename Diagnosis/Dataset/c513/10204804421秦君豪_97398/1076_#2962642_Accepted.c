#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

char stack [101];
int sp=0;
char top()
{
    return stack [sp-1];
}
void push(char s)
{
    stack[sp++]=s;
}
char pop()
{
    return stack[--sp];
}

int isEmpty()
{
    return(sp==0);
}
void clear(void)
{
	memset(stack, 0, sizeof(stack));
	sp = 0;
}
int main(void)
{
    int T;
    scanf("%d",&T);
    char c=getchar();
    for(int i =0;i<T;i++)
    {
        int isPerfect=1;
        while ((c=getchar())!='\n')
        {
//            printf("c=%c\n",c);
            if(c=='('||c=='['||c=='{')
            {
                if (c=='('&&!isEmpty())
                {
                    if (top()!='[')
                    {
                        isPerfect=0;
                    }
                }
                else if (c=='['&&!isEmpty())
                {
                    if (top()!='{')
                    {
                        isPerfect=0;
                    }
                }
                else if(c=='{'&&!isEmpty())
                {
                    if(top()!='(')
                    {
                        isPerfect=0;
                    }
                 }
                 push (c);
            }
            else if(c==')'||c=='}'||c==']')
            {
                if (c==')')
                {
                    if(top()!='(')
                        isPerfect=0;
                    else
                        pop();
                }
                else if(c==']')
                {
                    if(top()!='[')
                        isPerfect=0;
                    else
                        pop();
                }
                else if (c=='}')
                {
                    if(top()!='{')
                        isPerfect=0;
                    else
                        pop();
                }
            }


        }
        if (!isEmpty())
            isPerfect=0;
            clear();
        if(isPerfect==0)
            printf("No\n");
        else
            printf("Yes\n");
    }
}
