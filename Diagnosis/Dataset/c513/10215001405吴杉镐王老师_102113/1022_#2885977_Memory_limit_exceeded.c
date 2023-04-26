#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct an
{
    char hash[1000001];
    char res[1000001];
    char s[1000001];
};

typedef struct an ans;

int cmp(const void* a,const void* b)
{
    ans m=*(ans*)a;
    ans n=*(ans*)b;
    if(strcmp(m.res,n.res)==0)
    {
        return strcmp(n.hash,m.hash);
    }
    else
    {
        return strcmp(m.res,n.res);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    ans val[n];
    for(int i=0;i<n;i++)
    {
        scanf("%s",val[i].s);
        int j=0;
        while(val[i].s[j]!='@')
            j++;
        strncpy(val[i].hash,val[i].s,i);
        for(int k=0;val[i].s[j+1+k]!='\0';k++)
        {
            val[i].res[k]=val[i].s[j+1+k];
        }
    }
    qsort(val,n,sizeof(val[0]),cmp);
    for(int k=0;k<n;k++)
    {
        printf("%s\n",val[k].s);
    }
    return 0;
}
