#include <stdio.h>
#include <string.h>
int alpha[130];
int main()
{
    char s[1000001];
    gets(s);
    int len = strlen(s);
    int l=1,loc=0,k;
    for(int i=0;i<len;i++)
    {
        memset(alpha,0,sizeof (alpha));
        k=0;
        for(int j=i;j<len && k<70;j++,k++)
        {
            if(alpha[s[j]] > 0)
            {
                if(k>l)
                {
                    l=k;
                    loc = i;
                }
                break;
            }
            alpha[s[j]] ++;
        }
        if(k>l)
        {
            l=k;
            loc=i;
        }
    }
    for(int j=0;j<l;j++)
    {
        printf("%c",s[loc+j]);
    }
    return 0;
}