#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {double rate;char word;} new1;
new1 q[27];
int cmp(const void *a,const void *b)
{
    char *a1=(char *)a,*b1=(char *)b;
    char a2=(*a1<'A')? *a1-'a'+'A':*a1;
    char b2=(*b1<'A')? *b1-'a'+'A':*b1;
    if ((q[a2-'A'].rate-q[b2-'A'].rate)>0) return -1;
    else if ((q[a2-'A'].rate-q[b2-'A'].rate)<0) return 1;
    else if (*a1-*b1>0) return 1;
    else return -1;
}
int main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        for (int j=0;j<26;j++)
        {
            q[j].word='A'+j;
            scanf("%lf",&q[j].rate);
        }
        char s[101]={"0"};
        gets(s);
        qsort(s,strlen(s),sizeof(s[0]),cmp);
        printf("case #%d:\n",i);
        for (int j=0;j<strlen(s);j++)
        {
            printf("%c",s[j]);
        }
        printf("\n");
    }
    return 0;
}
