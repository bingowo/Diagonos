#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
int gcd(int a,int b)
{
    if(b==0)return a;
    else return gcd(b,a%b);
}
int main()
{
    char s[20];
    scanf("%s",s);
    int flag=1;
    int i=0;
    int a=0,b=0,c=0;
    while(i<strlen(s))
    {
        if(s[i]=='+')
        {
            flag=1;i++;
        }
        else if(s[i]=='-')
        {
            flag=-1;i++;
        }
        int xi=0;
        while(isdigit(s[i]))
        {
            xi=xi*10+(s[i]-'0');
            i++;
        }
        xi*=flag;
        if(xi==0) xi=flag;
        if(s[i]=='x')
        {
            i++;
            if(s[i]=='^')
            {
                i++;
                a=xi;
                i++;
            }
            else
            {
                b=xi;
            }
        }
        else
        {
            c=xi;
        }
    }
    if(b*b<4*a*c) printf("No Answer!");
    else
    {
        int x1=-1*b-sqrt(b*b-4*a*c);
        int x2=2*a;
        int x3=-1*b+sqrt(b*b-4*a*c);
        int a1=1,c1=1,a2=1,c2=1;
        if(x2<0)
        {
            x2=-x2;
            x1=-x1;
            x3=-x3;
        }
        a1=x2/gcd(abs(x1),abs(x2));
        c1=x1/gcd(abs(x1),abs(x2))*(-1);
        a2=x2/gcd(abs(x2),abs(x3));
        c2=x3/gcd(abs(x2),abs(x3))*(-1);
        int t;
        if(a1>a2)
        {
            t=a1;a1=a2;a2=t;
        }
        if(c1>c2)
        {
            t=c1;c1=c2;c2=t;
        }
        printf("%d %d %d %d\n",a1,c1,a2,c2);
    }
    return 0;
}
