#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
//#include "myh.h"
typedef struct{char date[20];char time[10];int sz;char name[200];}fil;
int cmpn(const void*a,const void*b)
{
    fil fa=*(fil*)a,fb=*(fil*)b;
    return strcmp(fa.name,fb.name);
}
int cmps(const void*a,const void*b)
{
    fil fa=*(fil*)a,fb=*(fil*)b;
    return fa.sz<fb.sz?-1:1;
}
int cmpt(const void*a,const void*b)
{
    fil fa=*(fil*)a,fb=*(fil*)b;
    char ta[30]={},tb[30]={};
    strcat(ta,fa.date);strcat(ta,fa.time);
    strcat(tb,fb.date);strcat(tb,fb.time);
    return strcmp(ta,tb);
}

int main()
{
    int n;
    while(1)
    {
        scanf("%d",&n);
        if(!n)break;
        fil f[200];
        for(int i=0;i<n;i++)scanf("%s%s%d%s",f[i].date,f[i].time,&f[i].sz,f[i].name);
        char order[20];
        scanf("\nLIST /%s",order);
        //printf("!%c\n",order[0]);
        switch(order[0])
        {
        case 'N':
            qsort(f,n,sizeof(f[0]),cmpn);break;
        case 'S':
            qsort(f,n,sizeof(f[0]),cmps);break;
        case 'T':
            qsort(f,n,sizeof(f[0]),cmpt);break;
        }
        for(int i=0;i<n;i++)printf("%s %s %*d %s\n",f[i].date,f[i].time,16,f[i].sz,f[i].name);
        printf("\n");
    }
}
