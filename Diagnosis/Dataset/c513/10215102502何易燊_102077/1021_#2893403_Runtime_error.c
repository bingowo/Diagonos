#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <malloc.h>

int table[128];

int cmp(const void* a,const void* b)
{
    char* c = *(char**)a; char* d = *(char**)b;
    int i = 0;
    while (table[c[i]]==table[d[i]]) i++;
    return table[c[i]] - table[d[i]];
}

main()
{
    char s[128] = {};
    
    int k = 0;
    char p[21];
    while (scanf("%s",s)!=EOF)
    {
        for (int i=0;i<strlen(s);i++)
        {
            table[s[i]] = k;
            table[s[i]-'A'+'a'] = k++;
        }
        int j = 0;
        char* word[101];
        while (1)
        {
            char* q = (char*)malloc(2000);
            scanf("%s",p);
            strcpy(q,p);
            word[j++] = q;
            int ch = getchar();
            if (ch=='\n') break;
        }
        qsort(word,j,sizeof(s[0]),cmp);
        for (int z=0;z<j;z++) printf("%s ",word[z]);
        printf("\n");
    }
    system("pause");
    return 0;
}