#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct group{
    int date,year;
    char mouth[10];
};
int trans(const char* s){
    int t;
    if(strncmp(s,"pop",3)==0)t=0;
    if(strncmp(s,"no",2)==0)t=1;
    if(strncmp(s,"zip",3)==0)t=2;
    if(strncmp(s,"zotz",4)==0)t=3;
    if(strncmp(s,"tzec",4)==0)t=4;
    if(strncmp(s,"xul",3)==0)t=5;
    if(strncmp(s,"yoxkin",6)==0)t=6;
    if(strncmp(s,"mol",3)==0)t=7;
    if(strncmp(s,"chen",4)==0)t=8;
    if(strncmp(s,"yax",3)==0)t=9;
    if(strncmp(s,"zac",3)==0)t=10;
    if(strncmp(s,"ceh",3)==0)t=11;
    if(strncmp(s,"mac",3)==0)t=12;
    if(strncmp(s,"kankin",6)==0)t=13;
    if(strncmp(s,"muan",4)==0)t=14;
    if(strncmp(s,"pax",3)==0)t=15;
    if(strncmp(s,"koyab",5)==0)t=16;
    if(strncmp(s,"cumhu",5)==0)t=17;
    if(strncmp(s,"uayet",5)==0)t=18;
}

int cmp(const void *a,const void *b){
    struct group *g1=(struct group*)a,*g2=(struct group*)b;
    int t1=g2->l-g1->l,t2=-1;
    if((g1->m)>(g2->m))t2=1;
    if(t1)return t1;
    return t2;
}
int main(){
    int t,a=0;
    scanf("%d",&t);
    while(a<t){
        int n;
        scanf("%d",&n);
        struct group g[n];
        for(int i=0;i<n;i++){
            scanf("%d.",&g[i].date);
            scanf("%s",&g[i].mouth);
            scanf("%d",&g[i].year);
        }