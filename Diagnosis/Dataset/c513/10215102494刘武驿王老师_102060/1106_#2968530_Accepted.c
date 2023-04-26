#include<stdio.h>
#include<string.h>
int main()
{
    char s[2000];
    scanf("%s",s);
    if(strlen(s)==1)
    {
        printf("1");
        return 0;
    }
    long long int ans=1;
    if(s[0]!=s[1]) ans*=2;
    for(int j=1;j<strlen(s)-1;j++)
    {
        int m=1;
        if(s[j]!=s[j+1]) m++;
        if(s[j]!=s[j-1]&&s[j+1]!=s[j-1]) m++;
        ans*=m;
        ans%=1000000007;
    }
    if(s[strlen(s)-1]!=s[strlen(s)-2])
    {
        ans*=2;
        ans%=1000000007;
    }
    printf("%lld",ans);
}