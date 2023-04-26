#include<stdio.h>
#include<stdlib.h>

struct area{
    int r,h;long long c;
};

int cmp(const void *a,const void *b){
    struct area *g1=(struct area*)a,*g2=(struct area*)b;
    long long t=(g2->c)-(g1->c);
    if (t>0)return 1;
    else if(t<0)return -1;
    return 0;
}
long long Max(long long a,long long b){
    if(a>b)return a;
    return b;
}

int main(){
    int n,m,a=0;
    scanf("%d %d",&n,&m);
    struct area s[1000],s1[1000];
    while(a<n){
        scanf("%d %d",&s[a].r,&s[a].h);
        s[a].c=s[a].r*s[a].h;
        a++;
    }
    long long ans=0;
    for(int i=0;i<n;i++){
        int k=0;long long ar=0; 
        for(int j=0;j<n;j++)
            if(j!=i&&s[j].r<=s[i].r)s1[k++]=s[j];
        qsort(s1,k,sizeof(struct area),cmp);
        if(k!=0&&k>=m-1)for(int j=0;j<m-1;j++)ar+=s1[j].c;
        ans=Max(ans,ar*2+(long long)s[i].r*s[i].r+2*s[i].c);
    }
    
    printf("%lld",ans);
    return 0;
}