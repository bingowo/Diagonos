#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct group{
    int num,st;
};

int m;

int cmp(const void *a,const void *b){
    struct group *g1=(struct group*)a,*g2=(struct group*)b;
    int n1=g1->num,n2=g2->num,s1=g1->st,s2=g2->st;
    if(s1==m&&s2==m)return n1-n2;
    if(s1==m&&s2!=m)return 1;
    if(s1!=m&&s2==m)return -1;
    return s1-s2;
}

int cmp2(const void *a,const void *b){
    struct group *g1=(struct group*)a,*g2=(struct group*)b;
    int k=g1->num-g2->num;
    return k;
}

int main(){
    int n,k=0;
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
    qsort(g,n,sizeof(struct group),cmp);
    //printf("%d\n",m);
    for(int i=0;i<n;i++)printf("%d ",g[i].num);
}