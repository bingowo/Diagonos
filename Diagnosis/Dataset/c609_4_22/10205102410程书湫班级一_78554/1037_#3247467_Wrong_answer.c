#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int maxlen=0;
    int start=0;
    int alpha[128]={-1};
    int t=0;
    char s[1000000];
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++)
    {
        char c=s[i];
        if(alpha[c]>=t)
        {
            t=alpha[c]+1;
            alpha[c]=i;
        }
        else {
            alpha[c]=i;
            if(maxlen<i-t+1)
            {
                start=t;
                maxlen=i-t+1;
            }
        }
    }
    for(int j=start;j<start+maxlen;j++)
        printf("%c",s[j]);
    return 0;
}
