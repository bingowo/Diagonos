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
        char *a[1001];
        char word[50] = {};
        int q = 0;
        char *p;
        char s[501];
        gets(s);
        for (int j=0;s[j];j++)
        {
            if (s[j]!=' '&&s[j]!=','&&s[j]!='!'&&s[j]!='?') word[q++] = s[j];
            else
            {
                while (s[j]==' '||s[j]==','||s[j]=='!'||s[j]=='?') j++;
                j--;
                p = (char*)malloc(q);
                strcpy(p,word);
                a[k++] = p;
                memset(word,0,50);
                q = 0;
            }
        }
        qsort(a,k,sizeof(a[0]),cmp);
        printf("case #%d:\n%s ",i,a[0]);
        for (int j=1;j<k;j++) if (strcmp(a[j],a[j-1])) printf("%s ",a[j]);
        printf("\n");
    }
    return 0;
}