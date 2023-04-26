#include<stdio.h>
#include<stdlib.h>

struct group{
    int num,st;
};

int main(){
    int m,n;
    scanf("%d",&m);
    int a[m];memset(a,0,sizeof(a));
    for(int i=0;i<m;i++)scanf("%d",&a[i]);
    scanf("%d",&n);
    struct group g[n];
    for(int i=0;i<n;i++){g[i].num=0;g[i].st=m;}
    for(int i=0;i<n;i++)scanf("%d",&g[i].num);
    for(int i=0,i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i].num==a[j]){g[i].st==j;break;}
        }
    }
    qsort(g,n,sizeof(struct group),cmp);
}