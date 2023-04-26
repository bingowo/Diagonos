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
            count++;
            if(count>max) max=count-1;
        }
        else if(s[i]==s[i+1])
        {
            if(count>max) max=count;
            count=1;
        }
    }
    printf("%d",max);
    return 0;
}