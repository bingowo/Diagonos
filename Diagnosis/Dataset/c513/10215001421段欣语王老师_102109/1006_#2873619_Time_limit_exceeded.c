#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        char s[N];
        int ans=0;
        printf("case #%d:\n",i);
        scanf("%s",s);
        for(int i=0;s[N];i++)
        {
            if(s[i]=='-')ans=ans*3+(-1);
            else ans=ans*3+s[i]-'0';
        }
        printf("%d",ans);
    }
    return 0;
}