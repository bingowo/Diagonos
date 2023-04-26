#include<stdio.h>
#include<string.h>
int main()
{
    char s[1001];
    scanf("%s",&s);
    int l=strlen(s);
    int a[l];
    if(s[0]==s[1])
    {
        a[0]=1;
    }
    else
    {
        a[0]=2;
    }
    for(int i=1;i<l-1;i++)
    {
        if(s[i]==s[i-1]&&s[i]==s[i+1])
        {
            a[i]=1;
        }
        else if(s[i]!=s[i-1]&&s[i]!=s[i+1]&&s[i-1]!=s[i+1])
        {
            a[i]=3;
        }
        else
        {
            a[i]=2;
        }
    }
    if(s[l-2]==s[l-1])
    {
        a[l-1]=1;
    }
    else
    {
        a[l-1]=2;
    }
    unsigned long long result=1;
    for(int i=0;i<l;i++)
    {
        result=result*a[i];
        while(result>=1000000007)
        {
            result=result-1000000007;
        }
    }
    printf("%llu",result);
    return 0;
}
