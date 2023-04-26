#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int com(int a[])
{
    int prime[26]={97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};
    long long int ans=0;
    for(int i=0;i<26;i++)
    {
        ans=ans*prime[strlen(a)-1-i]+a[i];
    }
    return ans;
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
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        char s[1000];
        int a[26]={0};
        scanf("%s",s);
        Readnumber(s,a);
        printf("%lld",com(a));
    }
    return 0;
}