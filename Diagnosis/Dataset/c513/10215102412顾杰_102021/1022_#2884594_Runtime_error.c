#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
int cmp(const void*a,const void*b)
{
    char *pa=*(char**)a,*pb=*(char**)b,*da,*db;
    int i=0;
    while(*(pa+i)!='@')i++;
    da=pa+i;i=0;
    while(*(pb+i)!='@')i++;
    db=pb+i;i=0;
    if(strcmp(da,db)==0)return strcmp(pb,pa);
    else return strcmp(da,db);
}
int main() {
    int n,i;
    scanf("%d",&n);
    char s[100],*p,*em[333];
    for(i=0;i<n;i++)
    {
        scanf("%s",s);
        p=(char*)malloc(strlen(s)+1);
        strcpy(p,s);
        em[i]=p;
    }
    qsort(em,n,sizeof(em[0]),cmp);
    for(i=0;i<n;i++){printf("%s\n",em[i]);free(em[i]);}
    return 0;
}
