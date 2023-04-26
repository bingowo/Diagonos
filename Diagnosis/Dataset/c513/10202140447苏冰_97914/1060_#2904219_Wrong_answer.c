#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char s[110];
    scanf("%s",s);
    int cnt=0;int max=0;
    for(int i=0;i<strlen(s);i++)
    {
        if(isdigit(s[i]))
        {
            if(s[i]!='0')   cnt++;
            if(cnt>=max) max=cnt;
        }
        else
        {
            if(cnt>=max) max=cnt;
            cnt=0;
        }
    }
    printf("%d\n",max);
    return 0;
}
