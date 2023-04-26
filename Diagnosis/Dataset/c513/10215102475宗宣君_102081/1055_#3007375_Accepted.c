#include <stdio.h>
#include <string.h>
int main()
{
    char s[1000001];
    scanf("%s",s);
    int i,j = 0,p,maxlen = 0,start = 0;
    for(p = 0;s[p];p++)
    {
        int b[128] = {0},len = 0;
        for(i = p;s[i]&&b[s[i]]==0;i++)
        {
            len++;b[s[i]] = 1;
        }
        if(maxlen<len)
        {
            start = p;
            maxlen = len;
        }
    }
    for(j = start;j<start+maxlen;j++)
        printf("%c",s[j]);
    return 0;
}
