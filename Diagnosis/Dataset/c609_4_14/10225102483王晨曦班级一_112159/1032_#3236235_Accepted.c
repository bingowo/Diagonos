#include <stdio.h>
#include <string.h>

int main()
{
    char s[60]; scanf("%s",s);

    int cnt=1,big=1;
    for(int i=0; i<strlen(s)-1; i++)
    {
        if(s[i]!=s[i+1]) cnt++;
        else
        {
            if(cnt>big) big=cnt;
            cnt=1;
        }
    }
    if(cnt>big) big=cnt;

    printf("%d",big);

    return 0;
}

