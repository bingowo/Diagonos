#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[50];
    scanf("%s",s);
    int max=1;
    int count=1;
    int l=strlen(s);
    int i;
    for(i=0;i<l;i++)
    {
        if(s[i]!=s[i+1])
        {
            count++;continue;
        }
        else if(s[i]==s[i+1])
        {
            if(count>max) max=count;
            count=0;
        }
    }
    printf("%d",max+1);
    return 0;
}