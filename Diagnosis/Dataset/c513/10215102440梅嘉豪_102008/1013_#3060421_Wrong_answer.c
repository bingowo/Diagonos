#include <stdio.h>
#include <string.h>

int main()
{
    char s[1000];
    scanf("%s",s);
    char* p=strchr(s,'.');
    int ans=0,t;
    if(p==NULL)
    {
        for(int i=0;i<strlen(s);i++)
        {
            t=s[i]=='2'?-1:s[i]-'0';
            ans=ans*3+t;
        }
        printf("%d",ans);
    }
    else
    {

    }
}