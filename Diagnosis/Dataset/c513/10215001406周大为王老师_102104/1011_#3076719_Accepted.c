#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    long long int a=0,b=0,e=0;
    unsigned long long int x=0;
    char s[100000];
    int c[100000];
    int i=0;
    getchar();
    getchar();
    scanf("%s",s);
    int k=0;
    for(i=0;i<strlen(s);i++)
    {
        int d;
        if(s[i]>='A') d=s[i]-'A'+10;
        else d=s[i]-'0';
        unsigned int flag=8;
        while(flag)
        {
            if(d&flag) c[k++]=1;
            else c[k++]=0;
            flag=flag>>1;
        }
    }
    for(i=0;i<k;i++)
    {
        if(c[i]==1)
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

    if(b==0)
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
    else if(a!=0&&b>1)
        printf("%lld+%lldi",a,b);
    else if(a!=0&&b<0)
        printf("%lld%lldi",a,b);
    return 0;
}