#include <stdio.h>
#include <stdlib.h>
#include <string.h>
double RPN()
{
    char s[11];
    if(strchr("+-*/",(scanf("%s",s),*s)))
    {
        double val=RPN();
        switch(*s)
        {
            case '+':return val+RPN();
            case '-':return val-RPN();
            case '*':return val*RPN();
            case '/':return val/RPN();
        }
    }
    return atof(s);
}
int main()
{
    int n,i;
    for(scanf("%d",&n),i=0;i<n;i++)printf("case #%d:\n%lf\n",i,RPN());
    return 0;
}
