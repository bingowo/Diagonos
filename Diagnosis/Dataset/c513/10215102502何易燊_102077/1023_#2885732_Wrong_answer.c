#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getnum(char s[])
{
    int num = 0;
    for (int i=0;s[i];i++)
    {
        if (s[i]>='0'&&s[i]<='9') num = num*10 + s[i] - '0';
    }
    if (num==0) return -1;
    return num;
}

int cmp(const void* a,const void* b)
{
    char** c = (char**)a; char** d = (char**)b;
    int numc = getnum(*c); int numd = getnum(*d);
    if (numc!=numd) return numc-numd;
    else return strcmp(*c,*d);
}

main()
{
    char *array[101];
    char s[31];
    char *p;
    int i = 0;
    while (scanf("%s",s)!=EOF)
    {
        p = (char*)malloc((strlen(s)+1)*sizeof(char));
        strcpy(p,s);
        array[i++] = p;
    }
    qsort(array,i,sizeof(array[0]),cmp);
    for (int j=0;j<i;j++) printf("%s ",array[j]);
    return 0;
}