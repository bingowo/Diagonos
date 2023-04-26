#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a,const void* b)
{
    return strcmp(*(char**)a,*(char**)b);
}

main()
{
    int n;
    scanf("%d",&n);
    getchar();
    for (int i=0;i<n;i++)
    {
        int k = 0;
        char *a[10001];
        char word[1000];
        char *p;
        char* s = (char*)malloc(1000001);
        gets(s);
        for (int j=0;s[j];j++)
            if (s[j]==','||s[j]=='.'||s[j]=='!'||s[j]=='?') s[j] = ' ';
        while (sscanf(s,"%s",word)!=EOF)
        {
            p = (char*)malloc(strlen(word)+1);
            strcpy(p,word);
            a[k++] = p;
            s = strchr(s,' ')+1;
        }
        qsort(a,k,sizeof(a[0]),cmp);
        printf("case #%d:\n%s ",i,a[0]);
        for (int j=1;j<k;j++) if (strcmp(a[j],a[j-1])) printf("%s ",a[j]);
        printf("\n");
    }
    return 0;
}