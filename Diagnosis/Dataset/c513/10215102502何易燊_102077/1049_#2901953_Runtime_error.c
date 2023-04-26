#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

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
        char *a[500]; int p = 0;
        char s[500] = {};
        char temp[50] = {}; int k;
        char *word;
        gets(s);
        int index = 0;
        int alphanum = 0;
        int wordcnt = 0;
        while (s[index])
        {
            if (!(s[index]==' '||s[index]==','||s[index]=='.'||s[index]=='!'||s[index]=='?'))
            {
                alphanum++;
                temp[k++] = s[index];
            }
            else
            {
                if (temp[0]=='\0') {index++; continue;}
                word = (char*)malloc(alphanum+1);
                strcpy(word,temp);
                a[p++] = word;
                wordcnt++;
                alphanum = 0, k = 0;
                memset(temp,0,sizeof(temp));
            }
            index++;
        }
        qsort(a,wordcnt,sizeof(a[0]),cmp);
        printf("case #%d:\n%s ",i,a[0]);
        for (int j=1;j<wordcnt;j++) if (strcmp(a[j],a[j-1])!=0) printf("%s ",a[j]);
        printf("\n");
    }
    system("pause");
    return 0;
}