#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char s[100];
    int y,m,d,x,z,size;
    char name[64];
}N;
int cmp1(const void*a,const void*b)
{
    return strcmp(((N*)a)->name,((N*)b)->name);
}
int cmp2(const void*a,const void*b)
{
    if(((N*)a)->size-((N*)b)->size==0) return strcmp(((N*)a)->name,((N*)b)->name);
    return((N*)a)->size-((N*)b)->size;
}
int cmp3(const void*a,const void*b)
{
    if(((N*)a)->y!=((N*)b)->y) return ((N*)a)->y-((N*)b)->y;
    if(((N*)a)->m!=((N*)b)->m) return ((N*)a)->m-((N*)b)->m;
    if(((N*)a)->d!=((N*)b)->d) return ((N*)a)->d-((N*)b)->d;
    if(((N*)a)->x!=((N*)b)->x) return ((N*)a)->x-((N*)b)->x;
    if(((N*)z)->x!=((N*)b)->z) return ((N*)a)->z-((N*)b)->z;
    else return strcmp(((N*)a)->name,((N*)b)->name);
}
int main()
{
    N p[101];
    char l[10];
    int n=0,t=0,d=0,h=0;//d是判据
    while(scanf("%d\n",&n)&&n!=0){
    for(int i=0;i<n;i++){
        gets(p[i].s);
        p[i].y=atoi(p[i].s);
        p[i].m=atoi(p[i].s+5);
        p[i].d=atoi(p[i].s+8);
        p[i].x=atoi(p[i].s+11);
        p[i].z=atoi(p[i].s+14);
        p[i].size=atoi(p[i].s+20);
        strcpy(p[i].name,p[i].s+34);
    }
    scanf("%s",&l);
    scanf("%s",&l);
    if(l[1]=='N') qsort(p,n,sizeof(p[0]),cmp1);
    if(l[1]=='S') qsort(p,n,sizeof(p[0]),cmp2);
    if(l[1]=='T') qsort(p,n,sizeof(p[0]),cmp3);
    for(int i=0;i<n;i++) printf("%s\n",p[i].s);
    printf("\n");
    }
    return 0;
}
