#include <stdio.h>
#include <stdlib.h>
#include <string.h>
double t[26];
int cmp(const void *a,const void *b)
{
    char c=*((char *)a);
    char d=*((char *)b);
    char c1=c>='a'?(c-'a'):(c-'A');
    char c2=d>='a'?(d-'a'):(d-'A');
    if (t[c1]!=t[c2]) return t[c2]>t[c1];
    else if(c1==c2) return d>c;
    else return c1>c2;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++)
    {
        for(int i=0;i<26;i++)
        {
            scanf("%f",&t[i]);
        }
        char s[101];
        scanf("%s",s);
        qsort(s,strlen(s),sizeof(s[0]),cmp);
        printf("case #%d:\n",cas);
        printf("%s\n",s);
    }
    return 0;
}
