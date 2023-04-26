#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int a=0,b=0,e=0;
    int x=0;
    int s[1000];
    char c[1000];
    int len=0,i=0;
    getchar();
    getchar();
    scanf("%s",c);
    while(c[i])
    {
        if(c[i]<'A')
            x=x*16+c[i]-'0';
        else
            x=x*16+c[i]-'A'+10;
        i++;
    }
    while(x>0)
    {
        s[len]=x%2;
        x/=2;
        len++;
    }
    i=0;
    if(s[i]==1)
    {
        a=1;
        b=0;
        i++;
    }
    else if(s[i]==0&&len>1)
    {
        i++;
        if(s[i]==1)
        {
            a=-1;
            b=1;
        }
        else
        {
            a=0;
            b=1;
        }
    }
    while(i<len)
    {
        if(s[i]==1)
        {
            e=a;
            a=-a-b+1;
            b=e-b;
        }
        else
        {
            e=a;
            a=-a-b;
            b=e-b;
        }
        i++;
    }
    if(a==0&&b==0)
        printf("0");
    else if(a!=0&&b==0)
        printf("%lld",a);
    else if(a==0&&b==1)
        printf("i");
    else if(a==0&&b!=0)
        printf("%lldi",b);
    else if(b>1)
        printf("%lld+%lldi",a,b);
    else if(b==1)
        printf("%lld+i",a);
    else
        printf("%lld%lldi",a,b);
    return 0;
}
