#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max_erase(char s[])
{
    char t[102]="";
    int len=strlen(s);
     return 0;
}

int main()
{
    int T=0;
    scanf("%d",&T);
    getchar();
    for(int i=0;i<T;i++)
    {
         char s[101]="";
         gets(s);
         printf("case #%d:\n%d",i,max_erase(s));
    }
    return 0;
}

