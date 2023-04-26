#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mail
{
    char *name[1000];
    char *com[1000];
};

int main()
{
    int m;
    struct mail t[100];
    scanf("%d",&m);
    for(int z=0;z<m;z++)
    {
       scanf("%s@%s",t[z].name,t[z].com);
    }
    int cmp(const void *a1,const void *b1);
    qsort(t,m,sizeof(t[0]),cmp);
    for(int k=0;k<m;k++)
    {
        printf("%s",t[k].name);
        printf("@");
        printf("%s",t[k].com);
        printf("\n");
    }
    return 0;
}


int cmp(const void *a1,const void *b1)
{
    struct mail a=*(struct mail*)a1;
    struct mail b=*(struct mail*)b1;
    if(strcmp(a.com,b.com)>0)  return 1;
    else if(strcmp(a.com,b.com)==0)
    {
        if(strcmp(a.name,b.name)<0) return 1;
        else return -1;
    }
    else return -1;
}
