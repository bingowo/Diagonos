#include <stdio.h>
#include <string.h>
int main()
{
    char s[1000001];
    int a[124]= {0},begin = 0,rbegin = 0,len = 0,maxlen = 0,i;
    scanf("%s",s);
    for(i = begin;s[i];i++)
    {
        if(a[s[i]]==0) {a[s[i]] = -1;len++;}
        else
        {memset(a,0,sizeof(int)*124);
        if(maxlen<len) {
            if(begin == 0) rbegin = begin;
            else rbegin = begin + 1;
            begin += 1;
            maxlen = len;
            }
        len = 0;}
    }
    if(maxlen<len) {
            if(begin == 0) rbegin = begin;
            else rbegin = begin + 1;
            begin += 1;
            maxlen = len;
            }
    for(i = rbegin;i<rbegin+maxlen;i++)
        printf("%c",s[i]);
    return 0;
}
