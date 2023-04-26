#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char od[28];

int cmp(const void* a, const void* b)
{
    char *m = *(char**)a, *n = *(char**)b;
    int lem = strlen(m), len = strlen(n);
    int i, j, lent;
    lent = (lem > len) ? len : lem;

    for(i=0; i<lent; i++)
    {
        if((m[i]!=n[i])&&(m[i]!=(n[i]+32))&&((m[i]+32)!=n[i]))
        {
            for(j=0; j<26; j++)
            {
                if((m[i]==od[j])||(m[i]==(od[j]+32)))
                    return -1;
                if((n[i]==od[j])||(n[i]==(od[j]+32)))
                    return 1;
            }
        }
    }
    if(lem > len)
        return 1;
    if(lem < len)
        return -1;
}

int main()
{
    memset(od, 0, sizeof(char)*28);
    //char m = getchar();
    char m;
    scanf("%c", &m);
    while(m != EOF)
    {
        int i = 0, j = 0;
        od[0] = m;
        for(i=1; i<26; i++)
            od[i] = getchar();
        //m = getchar();

        char** num;
        num = (char**)malloc(sizeof(char*)*105);
        //char m;
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
        m = getchar();
    }
    return 0;
}
