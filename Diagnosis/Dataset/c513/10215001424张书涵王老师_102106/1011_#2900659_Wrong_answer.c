#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void reverse(char* s)
{
    int i,j;
    char c;
    for(i=0,j=strlen(s)-1;i<j;i++,j--)
    {
        c=s[i];
        s[i]=s[j];
        s[j]=c;
    }
}

int main()
{
    char s[1000];//s存储十六进制
    scanf("%s",s);
    int i,j=0;
    int n=0;
    char s2[10000]; //s2存储二进制
    for(i=0;s[i];i++)
    {
        if(s[i]<58)
            n=s[i]-48;
        else
            n=s[i]-55;
        for(;j<4*(i+1);j++)
        {
            s2[j]=n%2+48;
            n=n/2;
        }
    }
    long long int qr=0,qi=0;
    long long int a,b;
    for(i=0;s2[i];i++)
    {
        a=s2[i]-48-qr-qi;
        b=qr-qi;
        qr=a;
        qi=b;
    }
    if(a==0)
    {
        if(b!=1&&b!=-1)
                    printf("%lldi",b);
                else
                {
                    if(b==1)
                        printf("i");
                    else
                        printf("-i");
                }
    }
    else
    {
        if(b==0)
            {
                printf("%lld",a);
            }
        else
        {
            if(b>0)
                {
                    if(b==1)
                        printf("%lld+i",a);
                    else
                        printf("%lld+%lldi",a,b);
                }
            else
                {
                    if(b==-1)
                        printf("%lld-i",a);
                    else
                        printf("%lld%lldi",a,b);
                }
        }
    }
}

