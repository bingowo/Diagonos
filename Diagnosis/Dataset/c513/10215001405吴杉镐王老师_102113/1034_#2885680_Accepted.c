#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

double res[26];

int cmp(const void* a,const void* b)
{
    char m=*(char*)a;
    char n=*(char*)b;
    int p,q;
    if(m>='A' && m<='Z')
        p=(int)m-'A';
    else
        p=(int)m-'a';
    if(n>='A' && n<='Z')
        q=(int)n-'A';
    else
        q=(int)n-'a';
    if(p==q)
    {
        return (int)n-(int)m;
    }
    else
    {
        if(res[p]-res[q]<0.001)
            return 1;
        else
            return -1;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        for(int k=0;k<26;k++)
        {
            scanf("%lf",&res[k]);
        }
        char s[101]={'\0'};
        scanf("%s",s);
        unsigned long l=strlen(s);
        qsort(s,l,sizeof(s[0]),cmp);
        printf("%s\n",s);
    }
    return 0;
}
