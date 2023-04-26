#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i=0;
    scanf("%d",&i);
    char s[32769]={0};
    s[0]='0';
    for(int j=1;j<=i;j++)
    {
        char t[32769]={0};
        strcpy(t,s);
        for(int m=0;m<strlen(s);m++)
        {
            t[m]=t[m]=='0'?'1':'0';
        }
        strcat(s,t);
    }
    printf("%s",s);
    return 0;
}