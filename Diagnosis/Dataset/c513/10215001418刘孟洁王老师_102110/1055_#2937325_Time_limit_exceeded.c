#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[1000007] = {'\0'};
char s[1000007],t[1000007] = {'\0'};
int main()
{
    int i,k,len = 0,start;
    int p[128];
    for(i = 0; i < 128; i++)p[i] = -1;
    k = 0;
    scanf("%s",s);
    for(i = 0;i < strlen(s); i++)
    {
        if(p[s[i]] >= k)
        {
            k = p[s[i]]+1;
            p[s[i]] = i;
        }
        else
        {
            p[s[i]] = i;
            if(len < i-k+1)
            {
                start = k;
                len = i-k+1;

            }
        }
    }
    for(i = 0; i < len; i++)printf("%c",s[start+i]);
    return 0;
}