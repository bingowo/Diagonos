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
    return strncmp(a1->time,b1->time,64);
}
int cmpS(const void*a,const void *b)
{
    file *a1=(file*)a;
    file *b1=(file*)b;
    return strncmp(a1->size,b1->size,64);
}

int main()
{
    int n;
    int i,j;
    while(scanf("%d",&n)!=0)
    {
        file f[n];
        char code[10];
        for (i=0;i<n;i++)
        {
            scanf("%s",f[i].date);
            scanf("%s",f[i].time);
            scanf("%s",f[i].size);
            scanf("%s",f[i].name);
        }
        getchar();
        gets(code);
        if(code[6]=='N')
            qsort(f,n,sizeof(f[0]),cmpN);
        else if(code[6]=='S')
            qsort(f,n,sizeof(f[0]),cmpS);
        else if(code[6]=='T')
            qsort(f,n,sizeof(f[0]),cmpT);
        for(j=0;j<n;j++)
        {
            printf("%s ",f[i].date);
            printf("%s ",f[i].time);
            printf("%16s ",f[i].size);
            printf("%s\n",f[i].name);
        }
    }
    system("pause");
    return 0;
}
