#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[1000];
    scanf("%s",s);
    int len=strlen(s);
    long long int ans=1;
    if(len==1) ;
    else
        for(int i=0;i<len;i++)
        {
            if(i==0&&s[i+1]!=s[i]) ans=ans*2;
            else if(i==0&&s[i+1]==s[i]) continue;
            else if(i==len-1&&s[i]!=s[i-1]) ans*=2;
            else if(i==len-1&&s[i]==s[i-1]) continue;
            else if(s[i]==s[i-1]&&s[i]==s[i+1]) continue;
            else if(s[i]==s[i-1]&&s[i]!=s[i+1]) ans*=2;
            else if(s[i]!=s[i-1]&&s[i]==s[i+1]) ans*=2;
            else if(s[i]!=s[i-1]&&s[i]!=s[i+1]&&s[i-1]!=s[i+1]) ans*=3;
            else if(s[i]!=s[i-1]&&s[i]!=s[i+1]&&s[i-1]==s[i+1]) ans*=2;
        }
    printf("%lld\n",ans%1000000007);
    return 0;
}
