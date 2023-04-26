#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a,const void* b)
{
    return strcmp((char*)a,(char*)b);
}

void combination(char* s,char* char_comb)
{
    if (*s)
    {
        char left[17] = {0};
        sprintf(left,"%s%c",char_comb,s[0]);
        printf("%s\n",left);
        combination(s+1,left);
        combination(s+1,char_comb);
    }
}

main()
{
    int n; scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        int table[128] = {};
        char s[17] = {}; scanf("%s",s);
        char t[17] = {};
        for (int j=0,k=0;s[j];j++)
        {
            if (table[s[j]]==0) {t[k++] = s[j]; table[s[j]]++;}
        }
        qsort(t,strlen(t),sizeof(t[0]),cmp);
        char comb[100] = {};
        printf("case #%d:\n",i);
        combination(t,comb);
    }
    return 0;
}