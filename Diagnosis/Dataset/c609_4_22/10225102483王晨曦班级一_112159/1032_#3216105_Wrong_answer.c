#include <stdio.h>
#include <string.h>

int main()
{
    char s[60]; scanf("%s",s);

    int cnt=0,big=0;
    for(int i=0; i<strlen(s); i++)
    {
        if(s[i]!=s[i+1]) cnt++;
        else
        {
            if(s[i]=='|')
                {
                    cnt=0;
                    continue;
                }
                else cnt=1;
            }
            if(big<cnt) big=cnt;
    }
    printf("%d",big);

    return 0;
}

