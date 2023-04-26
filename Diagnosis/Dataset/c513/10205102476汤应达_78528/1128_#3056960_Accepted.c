#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#define maxn 301

int cmp(const void*a, const void*b)
{
    char *a0=*(char**)a,*b0=*(char**)b;
    return strcmp(a0,b0);
}

int main()
{
    int n,p=0;scanf("%d",&n);
    char**sites = (char**)malloc(sizeof(char*)*n);
    for(int i=0;i<n;i++)
        sites[i] = (char*)malloc(sizeof(char)*maxn);
    for(int i=0;i<n;i++)
    {
        scanf("%s",sites[p]);
        if(sites[p][4]=='s') memset(sites[p],0,sizeof(sites[p]));
        else p++;
    }
    qsort(sites,p,sizeof(sites[0]),cmp);
    for(int i=0;i<p;i++) printf("%s\n",sites[i]);

    return 0;
}