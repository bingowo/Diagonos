#include <stdio.h>
#include <string.h>

int main()
{
    char s[51];
    scanf("%s",s);
    int max=1,t=1;
    int len=strlen(s);
    int i=1;
    while(i<len)
    {
        if(s[i]==s[i-1])
        {
            if(t>max)max=t;
            t=1;
        }
        else t++;
        i++;
    }
    if(t>max)max=t;
    printf("%d",max);
    return 0;
}

