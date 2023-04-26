#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mail
{
    char name[10000];
    char com[10000];
};

int main()
{
    int m;
    struct mail t[100000];
    scanf("%d",&m);
    for(int z=0;z<m;z++)
    {
       int i=0,j=0;
       char temp[1000];
       scanf("%s",temp);
       while(temp[i]!='@')
       {
           t[z].name[i]=temp[i];
           i++;
       }
       while(temp[i]!='\0')
       {
           t[z].com[j]=temp[i];
           i++;
           j++;
       }
    }

    int cmp(const void *a1,const void *b1);
    qsort(t,m,sizeof(t[0]),cmp);
    for(int k=0;k<m;k++)
    {
        printf("%s",t[k].name);
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
