#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int temp,maxlen,i,j;
    char s[51];
    scanf("%s",s);
    temp=maxlen=1;
    for(i=0;i<strlen(s);i++)
    {
        for(j=i;j<strlen(s)-1;j++)
        {
            if(s[j]!=s[j+1])
            {
                temp++;
            }
            else if(s[j]==s[j+1])
            {
                maxlen=maxlen<temp? temp:maxlen;
                temp=1;
            }
        }
    }
    printf("%d",maxlen);
    return 0;
}

