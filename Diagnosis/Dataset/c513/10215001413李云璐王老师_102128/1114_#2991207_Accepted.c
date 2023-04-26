#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int gcd(int m,int n)
{
   if(m<n) {int c=m;m=n;n=c;}

   if(n==0) return m;
   else if(m%n==0) return n;
   else {m=m%n;return gcd(m,n);}
}

void solve(double a,double b,double c)
{
    double d=b*b-4*a*c;
    int flag=1;
    if(d<0) {printf("No Answer!");return;}
    char str[100];
    sprintf(str,"%g",sqrt(d));
    int l=strlen(str);
    for(int i=0;i<l;i++)
    if(str[i]=='.') {printf("No Answer!");;break;return;}
    int b1,b2,d1,d2,a1,a2,c1,c2,flag1=1,flag2=1;
    b1=b-sqrt(d);
    if(b1<0) {b1=-b1;flag1*=-1;}
    b2=b+sqrt(d);
    if(b2<0) {b2=-b2;flag2*=-1;}
    d1=d2=2*a;
    if(d1<0) {d1=-d1;d2=-d2;flag1*=-1;flag2*=-1;}
    c1=b1/gcd(b1,d1);
    c2=b2/gcd(b2,d2);
    a1=d1/gcd(b1,d1);
    a2=d2/gcd(b2,d2);
    if(flag1==-1) c1=-c1;
    if(flag2==-1) c2=-c2;
    if(a1>a2) printf("%d %d %d %d",a2,c2,a1,c1);
    else if(a1<a2) printf("%d %d %d %d",a1,c1,a2,c2);
    else if(a1==a2)
        {if(c1<c2) printf("%d %d %d %d",a1,c1,a2,c2);
        else printf("%d %d %d %d",a2,c2,a1,c1);}


}

int main()
{
    char s[100];
    scanf("%s",s);
    int a=0,b=0,c=0,tmp=0,flag=1;
    int i=0;
    while(s[i]!='\0')
    {
        if(s[i]=='-') flag=-1;
        else if(s[i]=='+') flag=1;
        else if(s[i]>='0'&&s[i]<='9')
        {
            tmp=tmp*10+s[i]-48;
            if(s[i+1]=='\0') {c=tmp*flag;tmp=0;}
        }
        else if(s[i]=='x')
           {
            if(s[i+1]=='^')
                {
                    if(tmp!=0) a=tmp*flag;
                    else a=flag;
                    i+=2;
                }
            else
            {if(tmp!=0) b=tmp*flag;
            else b=flag;}
            tmp=0;
            }

        i++;
    }
    solve(a,b,c);
    return 0;
}
