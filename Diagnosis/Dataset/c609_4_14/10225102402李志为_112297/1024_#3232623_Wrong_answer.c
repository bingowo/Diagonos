#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char s[100];
    int y,m,d;
    char name[64];
}N;
/*int cmp(const void*a,const void*b)
{
    if(((N*)a)->y!=((N*)b)->y) return ((N*)a)->y-((N*)b)->y;
    if(((N*)a)->m!=((N*)b)->m) return ((N*)a)->m-((N*)b)->m;
    return ((N*)a)->k-((N*)b)->k;
}*/
int main()
{
    N p[5];
    int n=0,t=0,l=0,d=0,h=0;//d是判据
    scanf("%d\n",&n);
    for(int i=0;i<n;i++){
        gets(p[i].s);
        p[i].y=atoi(p[i].s);
        printf("%d",p[i].y);
    }
    return 0;
}