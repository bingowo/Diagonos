#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int Romanum(char c)
{
    switch(c)
    {
        case 'I':return 1; break;
        case 'V':return 5; break;
        case 'X':return 10; break;
        case 'L':return 50; break;
        case 'C':return 100; break;
        case 'D':return 500; break;
        case 'M':return 1000; break;
        case '(':return 1000000; break;
        default: break;
    }
    return -1;
}

int main()
{
    char s[2000]={'\0'};
    long long res=0,t=0,m=1;
    int i;
    scanf("%s",s);
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]=='(')
        {
            res=res+t;
            t=0;
            m=m*1000;
        }
        else if(s[i]==')')
        {
            res=res+t*m;
            t=0;
            m=1;
        }
        else
        {
            if(Romanum(s[i])<Romanum(s[i+1])) t=t-Romanum(s[i]);
            else t=t+Romanum(s[i]);
        }
    }
    res=res+t;
    printf("%lld",res);
    return 0;
}
