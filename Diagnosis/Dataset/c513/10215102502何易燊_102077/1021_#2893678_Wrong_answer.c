#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <malloc.h>

int table[26];

int cmp(const void* a,const void* b)
{
    char *p, *q;
    p = (char*)a; q = (char*)b;
    char ch1, ch2;
    int i;
    for (i=0; ;i++)
    {
        ch1 = *(p+i), ch2 = *(q+i);
        if (ch1>='a') ch1 += 'A'-'a';
        if (ch2>='a') ch2 += 'A'-'a';
        if (ch1!=ch2) return table[ch1-'A']-table[ch2-'A'];
    }
}

main()
{
    char s[128] = {};
    char p[21];
    while (scanf("%s",s)!=EOF)
    {
        for (int i=0;i<26;i++) table[s[i]-'A'] = i;
        int j = 0;
        char word[101][21];
        while (1)
        {
            scanf("%s",word[j++]);
            int ch = getchar();
            if (ch=='\n') break;
        }
        qsort(word,j,sizeof(word[0]),cmp);
        for (int z=0;z<j;z++) printf("%s ",word[z]);
        printf("\n");
    }
    system("pause");
    return 0;
}