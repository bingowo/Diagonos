#include <stdio.h>
#include <string.h>
int main()
{
    char s[1000001];
    scanf("%s",s);
    int maxlen = 0;
    int start = 0,t,i;
    for(t = 0;s[t];t++)
    {
        int alpha[128] = {0},len = 0;
        for(i = t;s[i]&&alpha[s[i]]==0;i++)
        {
            alpha[s[i]] = 1;
            len++;
        }
        if(maxlen<len)
        {start = t;maxlen = len;}
    }
    for(i = start;i<start+maxlen;i++)
        printf("%c",s[i]);
    printf("\n");
    return 0;

}
