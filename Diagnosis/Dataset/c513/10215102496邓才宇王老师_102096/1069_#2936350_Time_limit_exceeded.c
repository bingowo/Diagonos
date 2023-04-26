#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int foreach(long long int m)
{
    char s[100];
    char s1[100];
    int i=0;
    while(m/10)
    {
        s[i++]=m%10;
        m=m/10;
    }
    s[i]=m;
    s[i+1]='\0';
    strcpy(s1,s);
    for(int j=0;j<strlen(s);i++)
    {
        char t;
        t=s[strlen(s)-j-1];
        s[strlen(s)-1-j]=s[j];
        s[j]=t;
    }
    return strcmp(s1,s);
}
int main()
{
    long long int n;
    scanf("%lld",&n);
    int num=0;
    while(1)
    {
        if(foreach(n)==0)
        {
            printf("%d %lld",num,n);
            break;
        }
        else
        {
            char s[100];
            int i=0;
            while(n/10)
            {
                s[i++]=n%10;
                n=n/10;
            }
            s[i]=n;
            s[i+1]='\0';
            long long q=0;
            for(int j=0;s[j];j++)
                q=q*10+s[j]-'0';
            n=q+n;
            num++;
        }
    }
}
