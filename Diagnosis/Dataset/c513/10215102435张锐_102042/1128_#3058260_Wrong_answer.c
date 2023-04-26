#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char s[500];
}Q;
int cmp(const void *a,const void *b)
{
    Q* s1=(Q*)a,*s2=(Q*)b;
    return strcmp(s1->s,s2->s);
}
int main()
{
    int n;
    scanf("%d",&n);
    Q* p=(Q*)malloc(n*sizeof(Q));
    for(int i=0;i<n;i++)
    {
        scanf("%s",p[i].s);
    }
    qsort(p,n,sizeof(p[0]),cmp);
    for(int i=0;i<n;i++)
    {
        if(i!=n-1)
        {
            if(strcmp(p[i].s,p[i+1].s)!=0) 
                if(p[i].s[4]!='s') printf("%s\n",p[i].s);
        }
        else printf("%s\n",p[i].s);
    }
    free(p);
    return 0;
}
