#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int num,sco;
}N;
int cmp(const void*a,const void*b)
{
    if(((N*)a)->sco==((N*)b)->sco) return ((N*)a)->num-((N*)b)->num;
    return ((N*)b)->sco-((N*)a)->sco;
}

int main()
{
    N p[11];
    int n=0,m=0,t=0,d=0,h=0;//dйгеп╬щ
    while(scanf("%d",&n)&&n!=0){
    for(int i=0;i<11;i++){
        p[i].sco = 0;
        p[i].num = i+1;
    }
    h=0;
    scanf("%d",&m);

    for(int i=0;i<m;i++){
        scanf("%d",&t);
        scanf("%d",&d);
        p[t-1].num=t;
        p[d-1].num=d;
        scanf("%d",&h);
        if(h==1) {
        p[t-1].sco+=3;
        p[d-1].sco-=1;
        }
        else if(h==0){
            p[t-1].sco++;
            p[d-1].sco++;
        }
        else if(h==-1) {p[d-1].sco+=3;
        p[t-1].sco-=1;
    }
    qsort(p,n,sizeof(p[0]),cmp);
    for(int i=0;i<n;i++) printf("%d ",p[i].num);
    printf("\n");
    }

    return 0;
}