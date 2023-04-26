#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct group{
    int num,st;
};

int cmp1(const void *a,const void *b){
    struct group *g1=(struct group*)a,*g2=(struct group*)b;
    int s1=g1->st,s2=g2->st;
    return s1-s2;
}

int cmp2(const void *a,const void *b){
    int x=*(int*)a,y=*(int*)b;
    return x-y;
}

int main(){
    int m,n;
    scanf("%d",&m);
    int a[m];memset(a,0,sizeof(a));
    for(int i=0;i<m;i++)scanf("%d",&a[i]);
    scanf("%d",&n);
    int b[n];memset(b,0,sizeof(b));
    for(int i=0;i<n;i++)scanf("%d",&b[i]);
    struct group g[n];
    for(int i=0;i<n;i++){g[i].num=0;g[i].st=0;}
    int e[n],x=0,y=0;
    memset(e,0,sizeof(e));
    for(int i=0;i<n;i++){
        int j;
        for(j=0;j<m;j++){
            if(b[i]==a[j]){
                g[x].num=b[i];
                g[x].st=j;
                x++;break;
            }
        }
        if(j==m)e[y++]=b[i];
    }
    qsort(g,x,sizeof(struct group),cmp1);
    qsort(e,y,sizeof(int),cmp2);
    for(int i=0;i<x;i++)printf("%d ",g[i].num);
    for(int i=0;i<y;i++)printf("%d ",e[i]);
}