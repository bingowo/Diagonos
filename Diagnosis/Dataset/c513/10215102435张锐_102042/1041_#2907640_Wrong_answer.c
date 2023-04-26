#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[100];
    scanf("%s",s);
    int len=strlen(s);
    int num=0;
    for(int i=0;i<len;i++)
    {
        if(s[i]!=s[i+1]) {num++;i++;}
        else continue;
    }
    printf("%d",num);
}