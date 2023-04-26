#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count(char s[])
{
    int num=0;
    for(int i=0;i<strlen(s)-1;i++)
    {
        if(s[i]=='('&&s[i+1]==')') num++;
    }
}

int main()
{
    char s[150];
    scanf("%s",s);
    int num=count(s);
    printf("%d",num);
    return 0;
}
