#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int table[256];
int cmp(const void*a,const void*b)
{
    while(**(char**)a == **(char**)b)
    {
        (*(char**)a)++,(*(char**)b)++;
    }
    return table[toupper(**(char**)a)] - table[toupper(**(char**)b)];
}
int main()
{
    char order[27];
    char ch;
    while(scanf("%s",order) != EOF)
    {
        int i;
        char ch;

        for(i = 0;i < 26;i++)
            table[order[i]] = i;
        char s[21];
        char*input[100];
        for(i = 0;scanf("%s",s);i++)
        {
            int len = strlen(s);
            input[i] = (char*)malloc(len + 1);
            strcpy(input[i],s);
            if((ch = getchar()) == '\n')
                break;
        }
        qsort(input,i,sizeof(char*),cmp);
        for(int j = 0;j <= i;j++)
        {
            printf("%s%c",input[j],(j == i-1)?'\n':' ');
            free(input[j]);
        }

    }
    return 0;
}
