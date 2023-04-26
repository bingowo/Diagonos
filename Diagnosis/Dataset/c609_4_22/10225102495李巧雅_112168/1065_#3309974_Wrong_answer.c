#include <stdio.h>
#include <ctype.h>
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
double expr()
{
    char a[10];
    scanf("%s",a);
    double f1,f2;
    switch(a[0])
    {
        case'+':{f1=expr();f2=expr();return f1+f2;}
        case'-':{f1=expr();f2=expr();return f1-f2;}
        case'*':{f1=expr();f2=expr();return f1*f2;}
        case'/':{f1=expr();f2=expr();return f1/f2;}
        default:return atof(a);
    }
}
int main()
{
    int T;
    char a[100];
    int i;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%s",a);
        double expr();
    }
    return 0;
}

