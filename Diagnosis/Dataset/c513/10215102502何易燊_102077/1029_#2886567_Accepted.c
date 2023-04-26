#include <stdio.h>
#include <string.h>

main()
{
    int table[128] = {};
    char table_[201] = {};
    int index = 0;
    int n;
    scanf("%d",&n);
    getchar();
    char s[201];
    for (int i=0;i<n;i++)
    {
        char t[201] = {};
        gets(s);
        for (int j=0;s[j];j++) if (s[j]>='A'&&s[j]<='Z') table[s[j]]++;
        for (int j='A';j<='Z';j++)
        {
            for (int k=0;k<table[j];k++) table_[index++] = j;
        }
        index = 0;
        for (int j=0;s[j];j++)
        {
            if (s[j]<'A'||s[j]>'Z') t[j] = s[j];
            else t[j] = table_[index++];
        }
        memset(table,0,sizeof(table));
        memset(table_,0,sizeof(table_));
        memset(s,0,sizeof(s));
        index = 0;
        printf("case #%d:\n%s\n",i,t);
    }
    return 0;
}