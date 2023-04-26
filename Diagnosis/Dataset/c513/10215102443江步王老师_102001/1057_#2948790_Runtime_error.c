#include<stdio.h>

int main()
{
    char ch;
    char s[1001]={0};
    int n=0;
    int i;
    while ((ch = getchar()) != '\0')
    {
        if (ch>='a' && ch<='z')
        {
            ch-=32;
        }
        if (n == 0)
        {
            s[n++]=ch;
        }
        else
        {
            if (s[0] <= ch)
            {
                for (i=n;i>=1;i--)
                {
                    s[i]=s[i-1];
                }
                s[0]=ch;
                n++;
            }
            else
            {
                s[n++]=ch;
            }
        }
    }
    printf("%s",s);
    return 0;
}