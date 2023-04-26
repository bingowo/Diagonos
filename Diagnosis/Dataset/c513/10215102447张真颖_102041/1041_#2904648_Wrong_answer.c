#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[51];
    int maxlen=0;
    scanf("%s",s);
    for(int i=1;i<strlen(s);)
    {
        int t=0;
        if(s[i]!=s[i-1])
        {
            for(int j=i;j<strlen(s)&&s[j]!=s[j-1];j++)
           {
               t+=1;
               i++;
           }
           if(t+1>maxlen) maxlen=t+1;
        }
        else i++;
    }
    printf("%d",maxlen);
    return 0;
}
