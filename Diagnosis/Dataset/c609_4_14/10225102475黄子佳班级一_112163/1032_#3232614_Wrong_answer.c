#include <stdio.h>
#include <string.h>

int main()
{
    char s[51];
    scanf("%s",s);
    int cnt=0,max=1,t=1;
    int len=strlen(s);
    int i=1;
    while(i<len)
    {
        while(s[i-1]!=s[i])
        {
            t++;
            i++;
        }
        if(t>max)max=t;
        t=1;
        i++;
    }
    printf("%d",max);
    return 0;
}
