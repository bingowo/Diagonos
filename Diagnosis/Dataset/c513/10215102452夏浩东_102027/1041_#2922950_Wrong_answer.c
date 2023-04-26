#include <stdio.h>
int main()
{
    char s[51];
    scanf("%s",s);
    int len=1,temlen=1;
    for(int i=1;s[i]!='\0';i++)
    {
        if(s[i]!=s[i-1]) temlen++;
        if(s[i]==s[i-1]) len= len>temlen ? len:temlen;
    }
    len= len>temlen ? len:temlen;
    printf("%d",len);
    return 0;
}