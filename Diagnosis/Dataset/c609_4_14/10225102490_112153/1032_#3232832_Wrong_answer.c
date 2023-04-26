#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    char s[51];
    scanf("%s",s);
    int ans = 0;
    int i,len;
    for (i = 0; i <= strlen(s)-2; i++)
    {
        char c;
        c = s[i];
        if (c != s[i+1])
        {
            len++;
            //printf("len=%d\n",len);
        }
        else
        {
            ans = max(ans,len);
            len = 0;
        }

    }
    printf("%d",ans+1);
}