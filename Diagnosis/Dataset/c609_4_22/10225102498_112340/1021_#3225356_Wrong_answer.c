#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char od[26];

int cmp(const void* a, const void* b)
{
    char *m = *(char**)a, *n = *(char**)b;
    int lem = strlen(m), len = strlen(n);
    int i, j, lent;
    if(lem >= len)
        lent = len;
    else
        lent = lem;
    for(i=0; i<=26; i++)
    {
        if(i == 26)
        {
            if(lem >= len)
                return 1;
            else
                return -1;
        }

        for(j=0; j<lent; j++)
        {

            if(m[j]==od[i]||(m[j]==od[i]+32))
            {
                if(n[j]!=od[i]&&(n[j]!=od[i]+32))
                    return 1;
            }
            if(n[j]==od[i]||(n[j]==od[i]+32))
            {
                if(m[j]!=od[i]&&m[j]!=od[i]+32)
                    return -1;
            }
        }
    }
}

int main()
{
    scanf("%s", od) != EOF;

        char** num;
        num = (char**)malloc(sizeof(char*)*105);
        int i = 0, j = 0;
        char m;
        int flag = 0;
        for(j=0; j<105; j++)
        {
            num[j] = (char*)malloc(sizeof(char)*35);
            memset(num[j], 0, sizeof(char)*35);
        }
        for(i=0; i<105; i++)
        {
            scanf("%s", num[i]);
            m = getchar();
            if(m == '\n')
                break;
        }
        i++;

        qsort(num,i,sizeof(num[0]),cmp);
        for(j=0; j<i; j++)
        {
            printf("%s ", num[j]);
            free(num[j]);
        }
        printf("\n");
        free(num);

    return 0;
}
