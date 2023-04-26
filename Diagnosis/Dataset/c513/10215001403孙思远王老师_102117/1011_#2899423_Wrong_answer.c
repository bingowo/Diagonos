#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int a=1,b=0,e=0;
    unsigned long long int x=0;
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
    if(x==0)
    {
        printf("0");
        return 0;
    }
    while(x>0)
    {
        s[len]=x%2;
        x/=2;
        len++;
    }
    len--;
    while(len>0)
    {
        len--;
        if(s[len]==1)
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
    }

    if(a!=0&&b==0)
        printf("%lld",a);
    else if(a==0&&b==1)
        printf("i");
    else if(a==0&&b==-1)
        printf("-i");
    else if(b==-1)
        printf("%lld-i",a);
    else if(b==1)
        printf("%lld+i",a);
    else if(a==0&&b!=0)
        printf("%lldi",b);
    else if(b>1)
        printf("%lld+%lldi",a,b);
    else
        printf("%lld%lldi",a,b);
    return 0;
}
