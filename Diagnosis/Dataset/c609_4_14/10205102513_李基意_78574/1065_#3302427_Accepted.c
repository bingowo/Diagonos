#include<stdio.h>
#include<string.h>
#include<stdlib.h>

double exp()
{
    char s[10];
    scanf("%s",s);
    switch (s[0])
    {
    case '+':return exp() + exp();
    case '-':return exp() - exp();
    case '*':return exp() * exp();
    case '/':return exp() / exp();
    default: return atof(s);
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
        printf("case #%d:\n%lf\n",i,exp());
}
