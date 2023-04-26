#include<stdio.h>
#include<stdlib.h>

struct area{
    int r,h;long long c;
};

int cmp(const void *a,const void *b){
    struct area *g1=(struct area*)a,*g2=(struct area*)b;
    long long t1=(g1->c)-(g2->c);
    int m=0;
    if(t1>0)m=-1;
    else if(t1<0)m=1;
    return m;
}

int main(){
    int n,m,a=0;
    scanf("%d %d",&n,&m);
    struct area s[n],s1[n];
    while(a<n){
        scanf("%d %d",&s[a].r,&s[a].h);
        s[a].c=s[a].r*s[a].h;
    }
    long long ans;
    for(int i=0;i<n;i++){
        int k=0;long long ar=0; 
        for(int j=0;j<n;j++)
            if(j!=i&&s[j].r<=s[i].r)s1[k++]=s[i];
        qsort(s1,k,sizeof(struct area),cmp);
        for(int j=0;j<m-1;j++)ar+=s1[j].c;
        ans=Max(ans,ar*2+s1[i].r*s1[i].r+2*s1[i].c);
    }
    
    printf("%lld",ans);
}