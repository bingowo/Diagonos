#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXLINE 100

void insert(char *s,int pos)
{
    int i;
    for(i=strlen(s)+1;i>pos;i--)
        s[i]=s[i-1];
}

int main()
{
    char s[MAXLINE+1];
    scanf("%s",s);
    int len=strlen(s);
    char t[2*MAXLINE+1];
    for(int i=0;i<len;i++)
    {
        insert(strcpy(t,s),i);
        if(strcmp(t,s)<0)
        {
            len++;
            i++;
            strcpy(s,t);
        }
    }
    printf("%s\n",s);
    return 0;
}
