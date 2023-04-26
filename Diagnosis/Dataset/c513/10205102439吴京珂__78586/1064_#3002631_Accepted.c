#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double f()
{
    double f1,f2;
    char s[11];
    scanf("%s",s);
    if(s[0]=='+')
    {
        f1=f();f2=f();
        return f1+f2;
    }
    else if(s[0]=='-')
    {
        f1=f();f2=f();
        return f1-f2;
    }
    else if(s[0]=='*')
    {
        f1=f();f2=f();
        return f1*f2;
    }
    else if(s[0]=='/')
    {
        f1=f();f2=f();
        return f1/f2;
    }
    else return atof(s);
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n%f\n",i,f());
    }

    return 0;
}



