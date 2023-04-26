#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insert(int pos,char*t);

int main()
{
    char s[203],t[203];
    scanf("%s",s);
    int len=strlen(s);
    strcpy(t,s);
    for(int i=0;i<len;i++)
    {
        insert(i,t);
        if(strcmp(s,t)>0)
        {
            strcpy(s,t);
            len++,i++;
        }
        else
            strcpy(t,s);
    }
    printf("%s",s);
}

void insert(int pos,char*t)
{
    for(int i=strlen(t)+1;i>pos;i--)
        t[i]=t[i-1];
}
