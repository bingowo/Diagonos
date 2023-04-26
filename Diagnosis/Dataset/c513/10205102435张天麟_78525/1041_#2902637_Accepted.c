#include<stdio.h>
#include<string.h>
int main()
{
    char s[51];
    int len=1,i,ans=1;
    scanf("%s",s);
    for(i=1;i<strlen(s);i++)
    {
        if(s[i]!=s[i-1])
        {
            len++;
        }
        else
        {
            if(len>ans)
            {
                ans=len;
            }
            len=1;
        }
    }
    if(len>=ans)
    {
        ans=len;
    }
    printf("%d",ans);
    return 0;
}