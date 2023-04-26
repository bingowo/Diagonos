#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int top,S[1000];
void push(int x)
{
    top++;
    S[top]=x;
}
double pop()
{
    top--;
    return S[top+1];
}
int main()
{
    int T;
    char s[100];
    top=0;
    int i;
    int a,b;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        while(scanf("%s",s)!=EOF)
        {
            if(s[0]=='+'&&s[1]=='\0')
            {
                b=pop();
                a=pop();
                push(a+b);
            }
            else if(s[0]=='-'&&s[1]=='\0')
            {
                b=pop();
                a=pop();
                push(a-b);
            }
            else if(s[0]=='*'&&s[1]=='\0')
            {
                b=pop();
                a=pop();
                push(a*b);
            }
            else if(s[0]=='/'&&s[1]=='\0')
            {
                b=pop();
                a=pop();
                push(a/b);
            }
            else if(s[0]=='%'&&s[1]=='\0')
            {
                b=pop();
                a=pop();
                push(a%b);
            }
            else
            {
                push(atof(s));
            }
        }
        printf("case #%d\n",&i);
        printf("%lf",pop());
        return 0;
    }
}
double atof(char s[])
{
    double val,power;
    int i,sign;
    for(i=0;isspace(s[i]);i++);
    sign=(s[i]=='-')?-1:1;
    if(s[i]=='-'||s[i]=='+') i++;
    for(val=0;isdigit(s[i]);i++)
    {
        val=val*10+s[i]-'0';
    }
    if(s[i]=='.') i++;
    for(power=1;isdigit(s[i]);i++)
    {
        val=val*10+s[i]-'0';
        power*=10;
    }
    return sign*val/power;
}
