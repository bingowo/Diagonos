#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

double expr()
{
    char a[11];
    scanf("%s",a);
    double m,n;
    switch(a[0])
    {
    case'+':
    {
        m=expr();
        n=expr();
        return m+n;
    }
    case'-':
    {
        m=expr();
        n=expr();
        return m-n;
    }
    case'*':
    {
        m=expr();
        n=expr();
        return m*n;
    }
    case'/':
    {
        m=expr();
        n=expr();
        return m/n;
    }
    default:
    {
        return atof(a);
    }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    double r[T+1];
    for(int i=0; i<T; i++)
    {
        char ch=getchar();
        while(ch!='\0')
        {
            if(isspace(ch)) r[i]=expr();
            printf("case#%d:\n%.6f\n",i,r[i]);
        }
    }
    return 0;
}
