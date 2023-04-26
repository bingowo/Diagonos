#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAXN 201

char*ist(char*s,int pos)
{
    for(int i=strlen(s)+1;i>pos;i--)
    {
        s[i]=s[i-1];
    }
    return s;
}

int main()
{
    char s1[MAXN],s2[MAXN];
    scanf("%s",s1);
    int len=strlen(s1);
    for(int i=0;i<len;++i)
    {
        if(strcmp(ist(strcpy(s2,s1),i),s1)<0)
        {
            len++;
            i++;
            strcpy(s1,s2);
        }
    }
    printf("%s\n",s1);
    return 0;
}
