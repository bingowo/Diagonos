#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000020

int main()
{
    int start=0,len=0;
    char s[MAX]={0};
    int i,t;
    scanf("%s",s);
    int m[128];
    for (i=0;i<128;i++)
        m[i]=-1;
    char c;
    for (i=0;s[i];i++)
    {
        c=s[i];
        if (m[c]>=t)
        {
            t=m[c]+1;
            m[c]=i;
        }
        else
        {
            m[c]=i;
            if (len<i-t+1)
            {
                start=t;
                len=i-t+1;
            }
        }
    }
    for (i=0;i<len;i++)
        printf("%c",s[start+i]);
    printf("\n");
    return 0;
}
