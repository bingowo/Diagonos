#include<stdio.h>

int main()
{
    char s[101];

    scanf("%s",s);
    int len=strlen(s);
    char *p=s;

    int ans=0;
    int max=0;
    while (*p)
    {
        if ((*p)>='1' && (*p)<='9')
        {
            ans=1;p++;
            while ((*p)>='0' && (*p)<='9')
            {
                ans++;p++;
            }
            if (ans>max)
            {
                max=ans;
            }
        }
        if (!(*p))
        {
            break;
        }
        p++;
    }
    printf("%d",max);
    return 0;
}