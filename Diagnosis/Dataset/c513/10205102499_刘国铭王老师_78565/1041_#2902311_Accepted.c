#include <stdio.h>
#include <string.h>

int main()
{
    char s[51];
    scanf("%s",&s);
    int n=strlen(s);
    int maxlen=1,len=1;
    for(int i=0;i<n-1;i++)
    {
        if(s[i]!=s[i+1])
        {
            len++;
        }
        else
        {
            if(len>maxlen)
                maxlen=len;
            len=1;
        }
    }
    if(len>maxlen)
        maxlen=len;
    printf("%d",maxlen);
    return 0;
}
