#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long getnum(char s[])
{
    int table[128];
    memset(table,-1,sizeof(table));
    char *p = s;
    table[*p] = 1;
    int R = 0;
    while (*++p) if (table[*p]==-1) {table[*p] = R; R = R?R+1:2;}
    if (R<2) R = 2;
    long long a = 0;
    p = s;
    while (*p) a = a*R+table[*p++];
    return a;
}

int cmp(const void* a,const void* b)
{
    char* a_ = (char*)a; char* b_ = (char*)b;
    if (getnum(a_)!=getnum(b_)) return (getnum(a_)-getnum(b_))<0?-1:1;
    else return strcmp(a_,b_);
}

main()
{
    int n; scanf("%d",&n);
    char s[10001][17] = {};
    for (int i=0;i<n;i++) scanf("%s",s[i]);
    qsort(s,n,sizeof(s[0]),cmp);
    for (int i=0;i<n;i++) printf("%s\n",s[i]);
    system("pause");
    return 0;
}