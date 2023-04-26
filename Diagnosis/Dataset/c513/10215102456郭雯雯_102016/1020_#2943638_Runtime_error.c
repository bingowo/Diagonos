#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct group{
    char date[11];char time[6];int size;char name[64];
};

int cmpn(const void* a,const void* b){
    struct group *g1=(struct group*)a,*g2=(struct group*)b;
    return strcmp(g1->name,g2->name);
}
int cmps(const void* a,const void* b){
    struct group *g1=(struct group*)a,*g2=(struct group*)b;
    int t=g1->size-g2->size;
    return t;
}
int cmpt(const void* a,const void* b){
    struct group *g1=(struct group*)a,*g2=(struct group*)b;
    if(strcmp(g1->date,g2->date)!=0)return strcmp(g1->date,g2->date);
    return strcmp(g1->time,g2->time);
}

int main(){
    int n;
    scanf("%d",&n);
    while(n){
        int m=n;
        struct group *g=(struct group*)malloc(sizeof(struct group)*m);
        //struct group g[m];
        char order[11];
        for(int i=0;i<m;i++)scanf("%s %s %d %s",g[i].date,g[i].time,&g[i].size,g[i].name);
        gets(order);gets(order);
        if(strcmp(order,"LIST /NAME")==0)qsort(g,n,sizeof(struct group),cmpn);
        if(strcmp(order,"LIST /SIZE")==0)qsort(g,n,sizeof(struct group),cmps);
        if(strcmp(order,"LIST /TIME")==0)qsort(g,n,sizeof(struct group),cmpt);
        for(int i=0;i<m;i++)printf("%s %s %16d %s",g[i].date,g[i].time,g[i].size,g[i].name);
        printf("\n");
        free(g);
        scanf("%d",&n);
    }
    return 0;
}