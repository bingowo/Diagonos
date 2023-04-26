#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[1000001];
    scanf("%s",s);
    int maxlen=0,start=0;
    for(int i=0;s[t];t++)
    {
        int a[128]={0},len=0;
        for(int j=i;s[j]&&a[s[j]]==0;i++)
        {
            a[s[j]]=1;
            len++;
        }
        if(maxlen<len)
        {
            start=t;
            maxlen=len;
        }
    }
    for(int i=start;i<start+maxlen;i++)
    printf("%c",s[i]);
    printf("\n");
    return 0;
}