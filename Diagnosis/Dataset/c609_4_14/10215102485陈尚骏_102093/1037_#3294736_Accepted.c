#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAXN 1000001

int main()
{
    char s[MAXN];
    scanf("%s",s);
    char c;
    int st,len=0,i=0,t=0;
    int a[128];
    for(;i<128;++i)
    {
        a[i]=-1;
    }
    for(i=0;s[i];++i)
    {
        c=s[i];
        if(a[c]>=t)
        {
            t=a[c]+1;
            a[c]=i;
        }
        else
        {
            a[c]=i;
            if(len<i-t+1)
            {
                st=t;
                len=i-t+1;
            }
        }
    }
    for(i=0;i<len;++i)
    {
        printf("%c",s[st+i]);
    }
    printf("\n");
    return 0;
}
