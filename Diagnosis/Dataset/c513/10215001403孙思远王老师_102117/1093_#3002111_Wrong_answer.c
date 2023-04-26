#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[102];
    int x[101]={0},i;
    gets(s);
    int n=strlen(s);
    for(i=0;i<n;i++)
        x[i]=s[n-1-i]-'0';
    x[0]++;
    for(i=0;i<101;i++)
        {
            if(x[i]>9)
            {
                x[i+1]++;
                x[i]=0;
            }
        }
    int flag=1;
    while(flag)
    {
        flag=0;
        for(i=100;i>=0;i--)
        {
            if(x[i]==9)
            {
                x[i+1]++;
                while(i>=0)
                {
                    x[i]=0;
                    i--;
                }
                flag=1;
            }
        }
        for(i=0;i<101;i++)
        {
            if(x[i]>9)
            {
                x[i+1]++;
                x[i]=0;
            }
        }
    }
    int a=x[100];
    for(i=99;i>=0;i--)
    {
        a=(x[i]+a*10)%9;
    }
    if(a==0)
        x[0]++;
    for(i=100;i>=0;i--)
        {
            if(x[i]!=0)
                break;
        }
    for(;i>=0;i--)
        printf("%d",x[i]);
    return 0;
}
