#include<stdio.h>
#include<stdlib.h>
#include<string.h>

double trans()
{
    char s[10]={0};
    scanf("%s",s);
    double x,y;
    if(s[0]=='+')
    {
        x=trans();
        y=trans();
        return x+y;
    }
    if(s[0]=='-')
    {
        x=trans();
        y=trans();
        return x-y;
    }
    if(s[0]=='*')
    {
        x=trans();
        y=trans();
        return x*y;
    }
    if(s[0]=='/')
    {
        x=trans();
        y=trans();
        return x/y;
    }
    else
    {
        double res=atof(s);
        return res;
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        printf("case #%d:\n",i);
        printf("%.6f\n",trans());
    }
}
