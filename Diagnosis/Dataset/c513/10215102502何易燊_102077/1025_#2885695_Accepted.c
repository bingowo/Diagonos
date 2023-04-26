#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

int getnum(char a[])
{
    int count[128] = {};
    int cnt = 0;
    for (int i=0;i<strlen(a);i++) if (count[a[i]]==0) {cnt++; count[a[i]]++;}
    return cnt;
}

int cmp(const void* a,const void* b)
{
    char** c = (char**)a; char** d = (char**)b;
    if (getnum(*c)!=getnum(*d)) return getnum(*d)-getnum(*c);
    else return strcmp(*c,*d);
}

main()
{
    int T;
    char* p;
    char s[101] = {};
    scanf("%d",&T);
    char* array[101];
    for (int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        for (int j=0;j<n;j++)
        {
            scanf("%s",s);
            p = (char*)malloc(101);
            strcpy(p,s);
            array[j] = p;
        }
        qsort(array,n,sizeof(array[0]),cmp);
        printf("case #%d:\n",i);
        for (int j=0;j<n;j++) printf("%s\n",array[j]);
    }
    return 0;
}