#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
int t, c;
double exp()
{
    char s[12];
    scanf("%s",s);
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
    scanf("%d\n",&t);
    while(t--)
        printf("case #%d:\n%lf\n",c++ ,exp());
}