#include<stdio.h>
#include<stdlib.h>
#define N 10
double eval()
{
    char s[N+1];
    if(strchr("+-*/",(scanf("%s",s),*s)))
    {
        double opd1=eval(),opd2=eval();
        switch(*s)
        {
            case '+':return opd1+opd2;
            case '-':return opd1-opd2;
            case '*':return opd1*opd2;
            case '/':return opd1/opd2;
        }
    }
    return atof(s);
}
int main()
{
    int t,i,n;
    for(scanf("%d",&t),i=0;i<t;i++)printf("case #%d:\n""%f\n",i,eval());
    return 0;
}