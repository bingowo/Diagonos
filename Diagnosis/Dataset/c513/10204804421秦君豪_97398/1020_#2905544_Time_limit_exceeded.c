#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char date[11];
    char time[6];
    char size[10];
    char name[64];
}file;

int cmpN(const void*a,const void *b)
{
    file *a1=(file*)a;
    file *b1=(file*)b;
    return strncmp(a1->name,b1->name,64);
}
int cmpT(const void*a,const void *b)
{
    file *a1=(file*)a;
    file *b1=(file*)b;
    return strncmp(a1->date,b1->date,12);
}
int cmpS(const void*a,const void *b)
{
    file *a1=(file*)a;
    file *b1=(file*)b;
    return strncmp(a1->size,b1->size,12);
}

int main()
{
    int n;
    int i,j;
    char instruction[5], temp[5];
    while(scanf("%d",&n)!=0)
    {
        file* f=(file*)malloc(sizeof(f[0])*n);
        char code[11];
        for (i=0;i<n;i++)
        {
            scanf("%s",f[i].date);
            scanf("%s",f[i].time);
            scanf("%s",f[i].size);
            scanf("%s",f[i].name);
        }
        scanf("%s %s", temp, instruction);
        if(strcmp(instruction, "/NAME")=='N')
            qsort(f,n,sizeof(f[0]),cmpN);
        else if(strcmp(instruction, "/SIZE")=='S')
            qsort(f,n,sizeof(f[0]),cmpS);
        else if(strcmp(instruction, "/TIME")=='T')
            qsort(f,n,sizeof(f[0]),cmpT);
        for(j=0;j<n;j++)
        {
            printf("%s ",f[j].date);
            printf("%s ",f[j].time);
            printf("%16s%c",f[j].size,' ');
            printf("%s\n",f[j].name);
        }
        printf("\n");
        free(f);
    }
    system("pause");
    return 0;
}
