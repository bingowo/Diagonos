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
        int t=1;
        if(s[i]!=s[i-1])
        {
            for(int j=i;j<strlen(s)&&s[j]!=s[j-1];j++)
           {
               t+=1;
               i++;
           }
        }
        if(t>maxlen) maxlen=t;
        else i++;
    }
    if(strlen(s)==1) maxlen=1;
    printf("%d",maxlen);
    return 0;
}
