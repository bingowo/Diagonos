#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    unsigned int p=0;
    char s[31];
    gets(s);
    long long a=0;
    long long b=0, c=1;
    for (;p<strlen(s);p++) 
    {
        if (s[p]=='.') break;
        a = a *3;
        if (s[p]=='1') a += 1;
        if (s[p]=='2') a -= 1;
    }
    p++;
    for (;p<strlen(s);p++) 
    { 
        b =b * 3;      
        if (s[p]=='2') b -= 1;
        if (s[p]=='1') b += 1;  
        c = c * 3;      
    }
    if(a>0&&b<0)
    {
        a--;
        b=c+b;
    }
    else if(a<0&&b>0)
    {
        a++;
        b=c-b;
    }
    if (b==0) 
        printf("%lld\n",a);
    else
        {   
            if (a!=0) 
                printf("%lld ",a);
            printf("%lld %lld\n",b,c);
        }

    return 0;
}