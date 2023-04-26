#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int t,c=0;
double exp()
{
    char s[101];
    fgets(s,101,stdin);
    switch (s[0])
    {
    case '+':return exp() + exp();
    case '-':return exp() - exp();
    case '*':return exp() * exp();
    case '/':return exp() / exp();
    return atof(s);
    }
}
int main()
{
    scanf("%d",&t);
    while(t--)
        printf("case #%d:\n%lf\n",c++,exp());
}

