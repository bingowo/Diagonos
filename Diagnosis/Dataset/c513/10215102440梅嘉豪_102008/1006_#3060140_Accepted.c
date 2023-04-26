#include <stdio.h>
#include <string.h>

int main()
{
    int T;
    char s[1000];
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%s",s);
        int ans=0;
        for(int j=0;j<strlen(s);j++)
        {
            ans=ans*3;
            if(s[j]=='-')   ans--;
            else if(s[j]=='1')   ans++;
        }
        printf("case #%d:\n%d\n",i,ans);
    }
}