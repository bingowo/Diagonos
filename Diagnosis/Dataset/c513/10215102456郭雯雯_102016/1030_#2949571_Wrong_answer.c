#include<stdio.h>
#include<stdlib.h>

struct group{
    long long m;int l;
};

int num(long long m){
    while(m>=10||m<=-10){
        m/=10;
    }
    int n=m;
    return n;
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
            scanf("%lld",&g[i].m);
            g[i].l=num(g[i].m);
        }
        qsort(g,n,sizeof(struct group),cmp);
        printf("case #%d:\n",a);
        for(int i=0;i<n-1;i++)printf("%lld ",g[i].m);
        printf("%lld\n",g[n-1].m);
        a++;
    }
}