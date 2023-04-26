#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int cmp(const void*a,const void*b)
{
    if(toupper(*(char*)a) == toupper(*(char*)b))
        return *(char*)a - *(char*)b;
    else
        return toupper(*(char*)a) - toupper(*(char*)b);
    
}
int main()
{
    int table[256],i,j,k;
    memset(table,0,sizeof(table));
    int T,m;
    scanf("%d",&T);
    for(m = 0;m < T;m++)
    {
        char s[17],t[17]; 
        scanf("%s",s);
        for(i = 0,j = 0;i < strlen(s);i++)
        {
            if(table[s[i]] == 0)
            {
                t[j++] = s[i];
                table[s[i]] = 1;
            }
        }
        t[j] = '\0';
        qsort(t,j,sizeof(char),cmp);
        int len = strlen(t);
        printf("case #%d:\n",m);
        for(i = 0;i < len;i++)
        {
            for(k = 1;k <= len - i;k++)
            {
                for(j = 0;j < k;j++)
                {
                    putchar(t[i+j]);
                }
                putchar('\n');
            }
        }
    }
}