#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char s[1000000];
    scanf("%s",s);
    int i,j;
    int begin;
    int maxlen = 0;
    int hash[256];
    int n = strlen(s);
    for(i=0; i<n; ++i)
    {
        memset(hash,0,sizeof(hash));
        hash[s[i]] = 1;
        for(j=i+1; j<n; ++j)
        {
            if(hash[s[j]] == 0)
                hash[s[j]] = 1;
            else
                break;
        }
        if(j-i > maxlen)
        {
            maxlen = j-i;
            begin = i;
        }
    }
    for(int k=begin;k<begin+maxlen;k++)
        printf("%c",s[k]);
    return 0;
}