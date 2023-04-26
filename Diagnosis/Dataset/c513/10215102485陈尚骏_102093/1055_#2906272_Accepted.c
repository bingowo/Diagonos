#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    char s[1000001];
    scanf("%s",s);
    char al;
    int st=0,len=0;
    int p[128];
    int i=0,t=0;
    for(i=0;i<128;i++)
    {
        p[i]=-1;
    }
    for(i=0;s[i];i++)
    {
        al=s[i];
        if(p[al]>=t)
        {
            t=p[al]+1;
            p[al]=i;
        }
        else{
            p[al]=i;
            if(len<i-t+1)
            {
                st=t;
                len=i-t+1;
            }
        }
    }
    for(i=0;i<len;i++)
    {
        printf("%c",s[st+i]);
    }
    printf("\n");
    return 0;
}
