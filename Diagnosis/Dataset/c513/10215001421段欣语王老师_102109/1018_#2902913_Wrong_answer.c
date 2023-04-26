#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int com(int a[],int p)
{
    int prime[26]={97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};
    double ans=0;
    if(p==1)return a[25];
    else 
    {
        for(int i=0;i<p;i++)
    {
        ans=ans*prime[25-p+1+i]+a[25-p+1+i];
    }
    return ans;
    }
}

char Readnumber(char s[],int a[])
{
    int k=25;
    for(int i=strlen(s)-1;i>=0;i--)
    {
        if(isdigit(s[i]))
        {
            if(isdigit(s[i-1]))
            {
                a[k--]=s[i]-'0'+10*(s[i-1]-'0');
                i--;
            }
            else a[k--]=s[i]-'0';
        }
    }
}

int main()
{
    char s[1000];
    int a[26]={0},p=0;
    scanf("%s",s);
    for(int i=0;s[i];i++)
    {
        if(s[i]==',')p++;
    }
    p++;
    Readnumber(s,a);
    printf("%lld",com(a,p));
    return 0;
}