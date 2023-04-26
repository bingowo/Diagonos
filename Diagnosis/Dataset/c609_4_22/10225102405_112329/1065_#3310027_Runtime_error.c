#include<stdio.h>
#define N 100

double eval()
{
    char s[N+1];
    if(strchr("+-*/",scanf("%s",*s)))
    {
        double opdl=eval();
        switch(*s)
        {
            case'+':return opdl+eval();
            case'-':return opdl-eval();
            case'*':return opdl*eval();
            case'/':return opdl/eval();
        }
    }
    return atof(s);
}
int main()
{
    int i,T,n;
    for(scanf("%d",&T),i=0;i<T;i++)
        printf("case #%d:\n""%f\n",i,eval());
    return 0;
}
