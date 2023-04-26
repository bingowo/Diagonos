#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define N 1000000007
int main()
{
    long long int ans=1;
    char s[1001];
    scanf("%s",s);
    int len=strlen(s);
    if(len==1)
        printf("1");
    else if(len==2)
    {
        if(s[0]==s[1])
            printf("1");
        else printf("4");
    }
    else
    {
        for(int i=0;i<len;i++)
    {
        if(i==0&&s[i]!=s[i+1])
        {
            ans=ans*2;
            ans%=N;
        }
        else if(i==len-1&&s[i]!=s[i-1])
        {
            ans=ans*2;
            ans%=N;
        }
        else if(i!=0&&i!=len-1&&((s[i]==s[i-1]&&s[i]!=s[i+1])||(s[i]==s[i+1]&&s[i]!=s[i-1])||(s[i+1]==s[i-1]&&s[i]!=s[i+1])))
        {
            ans=ans*2;
            ans%=N;
        }
        else if(i!=0&&i!=len-1&&s[i-1]!=s[i+1]&&s[i]!=s[i-1]&&s[i]!=s[i+1])
        {
            ans=ans*3;
            ans%=N;
        }
    }
    printf("%lld",ans);
    }
    return 0;

}