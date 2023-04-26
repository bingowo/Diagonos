#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
typedef struct SSS
{
    char s1[500000];
    char s2[500000];
}sss;
int cmp(const void*_a,const void*_b)
{
    sss* a=(sss*)_a;
    sss* b=(sss*)_b;
    if(strcmp((a->s2),(b->s2))!=0)
        return strcmp((a->s2),(b->s2));
    else return strcmp((b->s1),(a->s1));
}
int main()
{
    int n;
    scanf("%d",&n);
    sss* s = (sss*)malloc(n*sizeof(sss));
    char x[1000001];
    gets(x);
    for(int i=0;i<n;i++)
    {
        gets(x);
        int m=strchr(x,'@')-x;
        strncpy(s[i].s1,x,m);
        int j=0;
        m++;
        while(m<strlen(x))
        {
            s[i].s2[j]=x[m];
            m++;
            j++;
        }
    }
    qsort(s,n,sizeof(sss),cmp);
    for(int i=0;i<n;i++)
    {
        printf("%s@%s\n",s[i].s1,s[i].s2);
    }
    free(s);
    return 0;
}
