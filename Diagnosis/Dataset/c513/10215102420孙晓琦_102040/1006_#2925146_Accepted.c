#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[1000000]="";

int main()
{
    int t;
    scanf("%d",&t);
    for (int i=0;i<t;i++)
    {
        int ans=0,j=0;
        scanf("%s",s);
        int len=strlen(s);
        for (;j<len-1;j++)
        {
            if (s[j]=='-')ans=(ans-1)*3;
            else
                ans=(ans+(s[j]-'0'))*3;
        }
        if(s[len-1]=='-')ans+=-1;
        else ans+=(s[j]-'0');
        printf("case #%d:\n%d\n",i,ans);
    }
}
