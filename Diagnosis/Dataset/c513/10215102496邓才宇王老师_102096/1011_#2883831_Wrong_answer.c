#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    typedef struct
    {
        char c;
        long long int a;
        long long int b;
    }S;
    char s[100];
    scanf("%s",s);
    S s1[100];
    for(int j=0;j<strlen(s)-2;j++)
    {
        if(s[j+2]=='0')
        {
            s1[j].a=0;
            s1[j].b=0;
        }
        if(s[j+2]=='1')
        {
            s1[j].a=1;
            s1[j].b=0;
        }
        if(s[j+2]=='2')
        {
            s1[j].a=-1;
            s1[j].b=1;
        }
        if(s[j+2]=='3')
        {
            s1[j].a=0;
            s1[j].b=1;
        }
        if(s[j+2]=='4')
        {
            s1[j].a=0;
            s1[j].b=-2;
        }
        if(s[j+2]=='5')
        {
            s1[j].a=1;
            s1[j].b=-2;
        }
        if(s[j+2]=='6')
        {
            s1[j].a=-1;
            s1[j].b=-1;
        }
        if(s[j+2]=='7')
        {
            s1[j].a=0;
            s1[j].b=-1;
        }
        if(s[j+2]=='8')
        {
            s1[j].a=2;
            s1[j].b=2;
        }
        if(s[j+2]=='9')
        {
            s1[j].a=3;
            s1[j].b=2;
        }
        if(s[j+2]=='A')
        {
            s1[j].a=1;
            s1[j].b=3;
        }
        if(s[j+2]=='B')
        {
            s1[j].a=2;
            s1[j].b=3;
        }
        if(s[j+2]=='C')
        {
            s1[j].a=2;
            s1[j].b=0;
        }
        if(s[j+2]=='D')
        {
            s1[j].a=3;
            s1[j].b=0;
        }
        if(s[j+2]=='E')
        {
            s1[j].a=1;
            s1[j].b=1;
        }
        if(s[j+2]=='F')
        {
            s1[j].a=2;
            s1[j].b=1;
        }
    }
    long long int a=0,b=0;
    for(int i=2;i<strlen(s);i++)
    {
        a=a*(-4)+s1[i-2].a;
        b=b*(-4)+s1[i-2].b;
    }
    printf("%lld%lldi",a,b);

}
