#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

double table[26];
int cmp(const void *a,const void *b)
{
    char A=*(char *)a;
    char B=*(char *)b;
    if(toupper(A)==toupper(B))
        return A>B?-1:1;
    else
        return table[toupper(A)-'A']>table[toupper(B)-'A']?-1:1;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int Case=0;Case<T;Case++)
    {
        for(int i=0;i<26;i++)
            scanf("%lf",&table[i]);
            getchar();
        char str[101]={0};
        int n=0;
        while((str[n]=getchar())!='\n')
            n++;
        qsort(str,n,sizeof(char),cmp);
        printf("case #%d:\n%s",Case,str);
    }
    return 0;
}