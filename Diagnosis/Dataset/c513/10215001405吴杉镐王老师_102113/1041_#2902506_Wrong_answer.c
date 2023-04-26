#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char s[51];
    scanf("%s",s);
    int cnt=1;
    int max=1;
    int len=strlen(s);
    for(int i=1;i<len;i++)
    {
        if(s[i]!=s[i-1])
            cnt++;
        else
        {
            if(cnt>max)
                max=cnt;
            cnt=1;
        }
    }
    printf("%d",max);
}
