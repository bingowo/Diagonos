#include<stdio.h>
#include<string.h>

int main()
{
    int i,j,k,t,l;
    long long int sum=1;
    char s[1007];
    scanf("%s",s);
    l=strlen(s);
    if(s[0]==s[1]) sum=1;
    else sum=2;
    for(i=1;i<l-1;i++)
    {
        if(s[i]==s[i-1]&&s[i]==s[i+1]) sum*=1;
        else if((s[i]==s[i-1]&&s[i]!=s[i+1])||(s[i]==s[i+1]&&s[i]!=s[i-1])) sum*=2;
        else if(s[i]!=s[i-1]&&s[i]!=s[i+1]) sum*=3;
    }
    if(s[l-1]==s[l-2]) sum*=1;
    else sum*=2;
    printf("%lld",sum);
    return 0;
}
