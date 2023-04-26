#include <stdio.h>
#include <stdlib.h>

int s[500]={0};
int top=0;

void push(int a)
{
    s[top++]=a;
}

int pop()
{
    int p=s[--top];
    return p;
}

int main()
{
    char str[500]={0};
    scanf("%s",str);
    for (int i=0;i<strlen(str);i++)
    {
        if (str[i]=='(')
            push(str[i]);
        if (str[i]==')')
        {
            if (s[top-1]=='(')
            {
                int c=pop();
                push(1);
            }
            else
            {
                int a=pop();
                int tmp=0;
                while(a!='(')
                {
                    tmp+=a;
                    a=pop();
                }
                push(2*tmp);
            }

        }
    }
    int sum=0;
    for (int i=0;i<top;i++)
        sum+=(s[i]);
    printf("%d\n",sum);
    return 0;
}
