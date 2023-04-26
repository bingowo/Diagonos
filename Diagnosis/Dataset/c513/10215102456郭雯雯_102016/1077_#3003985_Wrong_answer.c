#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct group{
    int num,st;
};

int cmp1(const void *a,const void *b){
    struct group *g1=(struct group*)a,*g2=(struct group*)b;
    int n=(g1->num-g2->num),s=(g1->st-g2->st);
    return s;
}

int cmp2(const void *a,const void *b){
    struct group *g1=(struct group*)a,*g2=(struct group*)b;
    int n=(g1->num-g2->num),s=(g1->st-g2->st);
    return n;
}

int main(){
    int m,n,k=0;
    scanf("%d",&m);
    int a[m];memset(a,0,sizeof(a));
    for(int i=0;i<m;i++)scanf("%d",&a[i]);
    scanf("%d",&n);
    struct group g[n];
    for(int i=0;i<n;i++){g[i].num=0;g[i].st=m;}
    for(int i=0;i<n;i++)scanf("%d",&g[i].num);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i].num==a[j]){g[i].st==j;k++;break;}
        }
    }
    qsort(g,n,sizeof(struct group),cmp1);
    qsort(g+k,n-k,sizeof(struct group),cmp2);
    for(int i=0;i<n;i++)printf("%d ",g[i].num);
}