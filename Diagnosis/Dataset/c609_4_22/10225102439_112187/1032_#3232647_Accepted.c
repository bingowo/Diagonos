#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[50];
    int len=0;
    scanf("%s",s);
    while (((s[len]=='|') || (s[len]=='-')) && (len<50)) len++;
    int cnt=1,max=1;
    for (int i=0;i<len-1;i++)
    {
        if (s[i]!=s[i+1]) cnt++;
        if (s[i]==s[i+1])
        {
            if (cnt>max) max=cnt;
            cnt=1;
        }
    }
    if (cnt>max) max=cnt;
    printf("%d",max);
    return 0;
}
