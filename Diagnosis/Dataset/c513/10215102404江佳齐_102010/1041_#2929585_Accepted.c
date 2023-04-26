#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[51];
    scanf("%s",s);
    int len=strlen(s);
    if(len<=1) printf("%d\n",len);
    else
    {
        int max=0,t;
    if(s[1]!=s[0]) max=2;
    else max=1;
    t=max;
    for(int i=2;i<len;i++)
    {
        if(s[i]!=s[i-1]) t++;
        else
        {
            max=max>t?max:t;
            t=1;
        }
    }
    max=max>t?max:t;
    printf("%d\n",max);
    }
    return 0;
}
