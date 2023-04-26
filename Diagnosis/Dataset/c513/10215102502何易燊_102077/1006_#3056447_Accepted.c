#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        char s[101] = {};
        scanf("%s",s);
        long long ans = 0;
        for (int j=0;s[j];j++)
        {
            if (s[j]=='-') ans = ans*3-1;
            else ans = ans*3+s[j]-'0';
        }
        printf("case #%d:\n%lld\n",i,ans);
    }
    return 0;
}