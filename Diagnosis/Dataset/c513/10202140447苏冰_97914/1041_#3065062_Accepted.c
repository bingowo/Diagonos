#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    char s[55];
    scanf("%s",s);
    int ans=1;
    int max=1;
    for(int i=0;i<strlen(s)-1;i++)
    {
        if(s[i]==s[i+1]) ans=1;
        else
        {
            ans++;
        }
        if(ans>=max) max=ans;
    }
    printf("%d\n",max);
    return 0;
}
