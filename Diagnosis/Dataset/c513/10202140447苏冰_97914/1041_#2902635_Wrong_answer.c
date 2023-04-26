#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[55];
int main()
{
    scanf("%s",s);
    int cnt=1;int max=1;
    int len=strlen(s);
    for(int i=0;i<len-1;i++)
    {
        if(s[i]!=s[i+1]) cnt++;
        else
        {
            if(cnt>=max) max=cnt;
            cnt=1;
        }
    }
    printf("%d",max);
    return 0;
}
