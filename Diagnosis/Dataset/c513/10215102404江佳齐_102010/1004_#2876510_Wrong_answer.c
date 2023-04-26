#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
int atof1(char s[])
{
    int val,power; int i,sigh;
    for(i=0;isspace(s[i]);i++);
    sigh=(s[i]=='-')?-1:1;
    if(s[i]=='-' || s[i]=='+') i++;
    for(val=0;isdigit(s[i]);i++) val=val*10+s[i]-'0';
    return sigh*val;
}

double atof2(char s[])
{
    double val,power; int i,sigh;
    for(i=0;isspace(s[i]);i++);
    sigh=(s[i]=='-')?-1:1;
    if(s[i]=='-' || s[i]=='+') i++;
    for(val=0;isdigit(s[i]);i++) val=val*10+s[i]-'0';
    if(s[i]=='.') i++;
    for(power=0;isdigit(s[i]);i++)
    {val=val*10+s[i]-'0';power++;}
    power=-power;
    if(power<0)
    {
        power=-power;
        return sigh*val/pow(10,power);
    }
    else return sigh*val*pow(10,power);
}

void soldouble(double d)
{
    int c=sizeof(d);
    unsigned char* p = (unsigned char*)&d;
    while(c--)
        printf("%02x",*p++);
    printf("\n");
}

void solint(int n)
{
    int c=sizeof(n);
    unsigned char* p=(unsigned char*)&n;
    while(c--)
        printf("%02x",*p++);
    printf("\n");
}

int main()
{
    char s[100];
    while(scanf("%s",s)!=EOF)
    {
        if(strchr(s,'.')==0) solint(atof1(s));
        else soldouble(atof2(s));
    }
    return 0;
}
