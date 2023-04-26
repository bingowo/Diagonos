#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct group{
    int year;int mou;int date;int hour;int minu;int size;
    char s[64];
};
int cmpn(const void* a,const void* b){
    struct group *g1=(struct group*)a,*g2=(struct group*)b;
    char *m=(char*)g1->s,*n=(char*)g2->s;
    return strcmp(m,n);
}
int cmps(const void* a,const void* b){
    struct group *g1=(struct group*)a,*g2=(struct group*)b;
    int t=g1->size-g2->size;
    return t;
}
int cmpt(const void* a,const void* b){
    struct group *g1=(struct group*)a,*g2=(struct group*)b;
    int t1=g1->year-g2->year,t2=g1->mou-g2->mou,t3=g1->date-g2->date,t4=g1->hour-g2->hour;
    if(t1)return t1;
    if(t2)return t2;
    if(t3)return t3;
    return t4;
}
void sortn(struct group *g,int n){
    qsort(g,n,sizeof(group),cmpn);
}

void sorts(struct group *g,int n){
    qsort(g,n,sizeof(group),cmps);
}

void sortt(struct group *g,int n){
    qsort(g,n,sizeof(group),cmpt);
}

int main(){
    int n;
    scanf("%d",&n);
    while(n!=0){
        int m=n;
        struct group g[m];
        char order[10];
        for(int i=0;i<m;i++){
            scanf("%d-%d-%d",&g[i].year,&g[i].mou,&g[i].date);
            scanf("%d:%d",&g[i].hour,&g[i].minu);
            scanf("%1",&g[i].size);
            scanf("%s",&g[i].s);
        }
        getline(order);getline(order);
        if(order=="LIST /NAME"){
            sortn(g,m);
            for(int i=0;i<m;i++){
                printf("%d-%d-%d ",g[i].year,g[i].mou,g[i].date);
                printf("%d:%d ",g[i].hour,g[i].minu);
                printf("%16d ",g[i].size);
                printf("%s\n",g[i].s);
            }
        }
        if(order=="LIST /SIZE"){
            sorts(g,m);
            for(int i=0;i<m;i++){
                printf("%d-%d-%d ",g[i].year,g[i].mou,g[i].date);
                printf("%d:%d ",g[i].hour,g[i].minu);
                printf("%16d ",g[i].size);
                printf("%s\n",g[i].s);
            }
        }
        if(order=="LIST /TIME"){
            sortt(g,m);
            for(int i=0;i<m;i++){
                printf("%d-%d-%d ",g[i].year,g[i].mou,g[i].date);
                printf("%d:%d ",g[i].hour,g[i].minu);
                printf("%16d ",g[i].size);
                printf("%s\n",g[i].s);
            }
        }
        printf("\n");
        scanf("%d",&n);
    }
}