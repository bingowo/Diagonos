#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[1000001];
    scanf("%s",s);
    int maxlen=0;//标记最长无重复子串
    int start=0;//标记最长无重复子串的起始位置
    for(int t=0;s[t];t++)
    {
        int alpha[128]={0},len=0;
        for(int i=t;s[i]&&alpha[s[i]]==0;i++)
        {
            alpha[s[i]]=1;
            len++;
        }
        if(maxlen<len)
        {
            start=t;maxlen=len;
        }
    }
    for(int i=start;i<start+maxlen;i++)
        printf("%c",s[i]);
    printf("\n");
    return 0;
}
