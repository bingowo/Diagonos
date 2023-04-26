#include<stdio.h>
#include<stdlib.h>

struct group{
    int num[55];int l;
};

int cmp(const void *a,const void *b){
    struct group *g1=(struct group*)a,*g2=(struct group*)b;
    for(int i=0;i<g1->l&&i<g2->l;i++){
        int n1=g1->num[i],n2=g2->num[i];
        if(n1!=n2)return n2-n1;
    }
    return (g2->l)-(g1->l);
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        struct group g[n];
        for(int i=0;i<n;i++){
            memset(g[i].num,0,sizeof(g[i].num));
            g[i].l=0;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<55;j++){
                int k;
                scanf("%d",&k);
                if(k!=-1)g[i].num[j]=k;
                else {g[i].l=j;break;}
            }
        }
        qsort(g,n,sizeof(struct group),cmp);
        for(int i=0;i<n;i++){
            for(int j=0;j<g[i].l;j++)
                printf("%d ",g[i].num[j]);
            printf("\n");
        }
    }
}