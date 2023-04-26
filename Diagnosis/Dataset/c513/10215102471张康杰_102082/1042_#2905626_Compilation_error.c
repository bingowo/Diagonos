#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int table[256],i,j,k;
    memset(table,0,sizof(table));
    char s[17],t[17];
    scanf("%d",s);
    for(i = 0,j = 0;i < strlen(s);i++)
    {
        if(table[s[i]] == 0)
        {
            t[j++] = s[i];
            table[s[i]] = 1;
        }
    }
    t[j] = '\0';
    int len = strlen(t);
    for(i = 0;i < len;i++)
    {
        for(k = 1;k < len;k++)
        {
            for(j = 0;j < k;j++)
            {
                putchar(t[i+j]);
            }
            putchar('\n');
        }
    }
}