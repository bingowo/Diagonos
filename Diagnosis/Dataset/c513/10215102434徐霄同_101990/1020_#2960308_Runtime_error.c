#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char d[11];
    char t[6];
    int s;
    char n[64];
} wj;
int cmpn(const void* a,const void* b)
{
    wj* a0=(wj*)a;
    wj* b0=(wj*)b;
    return strcmp(a0->n,b0->n);
}
int cmps(const void* a,const void* b)
{
    wj* a0=(wj*)a;
    wj* b0=(wj*)b;
    if(a0->s!=b0->s)
        return a0->s-b0->s;
    return strcmp(a0->n,b0->n);
}
int cmpt(const void* a,const void* b)
{
    wj* a0=(wj*)a;
    wj* b0=(wj*)b;
    if(strcmp(a0->d,b0->d)!=0)
        return strcmp(a0->d,b0->d);
    if(strcmp(a0->t,b0->t)!=0)
        return strcmp(a0->t,b0->t);
    return strcmp(a0->n,b0->n);
}
int main()
{
    wj a[100];
    char s[11];
    int i,n;
    scanf("%d",&n);
    while(n!=0){
        for(i=0;i<n;i++)
            scanf("%s%s%d%s",a[i].d,a[i].t,&a[i].s,a[i].n);
        getchar();
        gets(s);
        if(strcmp(s,"LIST /NAME")==0)
            qsort(a,n,sizeof(a[0]),cmpn);
        else if(strcmp(s,"LIST /SIZE")==0)
            qsort(a,n,sizeof(a[0]),cmps);
        else
            qsort(a,n,sizeof(a[0]),cmpt);
        for(i=0;i<n;i++)
            printf("%s %s %16d %s\n",a[i].d,a[i].t,a[i].s,a[i].n);
        printf("\n");
        scanf("%d",&n);
    }
    return 0;
}
