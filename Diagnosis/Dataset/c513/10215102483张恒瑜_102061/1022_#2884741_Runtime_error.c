#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
{
    char name[10000];
    char host[10000];
} email;

int cmp(const void* a, const void* b)
{
    email* p1=(email*)a;email* p2=(email*)b;
    if(!strcmp(p1->host,p2->host))
    {
        return strcmp(p2->name,p1->name);
    }
    strcmp(p1->host,p2->host);
}
int main()
{
    int n,i;
    scanf("%d",&n);
    email allemail[n];
    for(i=0;i<n;i++)
    {
        char tmp[10000];
        scanf("%s",&tmp);
        int j,p=0,flag=0;
        for(j=0;j<strlen(tmp);j++)
        {
            if(flag==1) allemail[i].host[p++]=tmp[j];
            if(tmp[j]=='@') {strncpy(allemail[i].name,tmp,j);allemail[i].name[j]='\0';flag=1;}
        }
        allemail[i].host[p]='\0';
    }
    qsort(allemail,n,sizeof(allemail[0]),cmp);
    for(i=0;i<n;i++)
    {
        printf("%s@%s\n",allemail[i].name,allemail[i].host);
    }
    return 0;
}