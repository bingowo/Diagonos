#include <stdio.h>
#include <stdlib.h>

char s[500]={0};
int top=0;

void push(char a)
{
    s[top++]=a;
}

char pop()
{
    char p=s[--top];
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
                char c=pop();
                push('1');
            }
            else
            {
                char a=pop();
                int tmp=0;
                while(a!='(')
                {
                    tmp+=a-'0';
                    a=pop();
                }
                push(2*tmp+'0');
            }

        }
    }
    int sum=0;
    for (int i=0;i<top;i++)
        sum+=(s[i]-'0');
    printf("%d\n",sum);
    return 0;
}