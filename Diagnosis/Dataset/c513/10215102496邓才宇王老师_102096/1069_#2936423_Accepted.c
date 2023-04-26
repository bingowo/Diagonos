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
        s[i++]=m%10+'0';
        m=m/10;
    }
    s[i]=m+'0';
    s[i+1]='\0';
    strcpy(s1,s);
    for(int j=0;j<strlen(s)/2;j++)
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
            char s3[100];
            int k=0;
            long long int m=n;
            while(m/10)
            {
                s3[k++]=m%10+'0';
                m=m/10;
            }
            s3[k]=m+'0';
            s3[k+1]='\0';
            long long int q=0;
            for(int j=0;s3[j];j++)
                q=q*10+s3[j]-'0';
            n=q+n;
            num++;
        }
    }
}
