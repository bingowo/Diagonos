#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[51];
    scanf("%s",s);
    int len=strlen(s);
    int max=0,length=1;
    char c=s[0];
    for(int i=1;i<len;i++){
        if(s[i]!=c) length++;
        else length=1;
        if(length>max) max=length;
        c=s[i];
    }
    printf("%d",max);
    return 0;
}
