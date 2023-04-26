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
    memset(stack,0,sizeof(stack));
}
int main()
{
    int t;
    scanf("%d",&t);
    char c=getchar();
    for(int i=0;i<t;i++)
    {
        int flag=1;
        while((c=getchar())!='\n')
        {
            if(c=='(')
            {
                if(!isEmpty())
                {
                    if(top()!='[')
                    {
                        flag=0;
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
                        flag=0;
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
                        flag=0;
                        break;
                    }
                }
                push(c);
            }
            else{
				if(c == ')' && top() == '(')
				{
					pop();
				}
				else if(c == ']' && top() == '[')
				{
					pop();
				}
				else if(c == '}' && top() == '{')
				{
					pop();
				}
				else
				{
					push(c);
				}

        }
        if(!isEmpty())
        {
            flag=0;
            cle();
        }
        if(flag)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
