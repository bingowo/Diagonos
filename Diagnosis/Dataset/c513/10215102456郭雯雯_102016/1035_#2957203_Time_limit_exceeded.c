#include<stdio.h>
#include<stdlib.h>

struct area{
    int r,h;
    long long d,c;
};

int cmp(const void *a,const void *b){
    struct area *g1=(struct area*)a,*g2=(struct area*)b;
    long long t1=(g1->d)-(g2->d),t2=(g1->c)-(g2->c);
    int m=0;
    if(t1>0)m=-1;
    else if(t1<0)m=1;
    else if(t2>0)m=1;
    else if(t2<0)m=-1;
    return m;
}

int cmp1(const void *a,const void *b){
    struct area *g1=(struct area*)a,*g2=(struct area*)b;
    long long t1=(g1->c)-(g2->c);
    int m=0;
    if(t1>0)m=-1;
    else if(t1<0)m=1;
    return m;
}

int main(){
    int n,m,a=0;long long ar=0; 
    scanf("%d %d",&n,&m);
    struct area s[n],s1[n];
    while(a<n){
        scanf("%d %d",&s[a].r,&s[a].h);
        s[a].d=s[a].r*s[a].r+2*s[a].r*s[a].h;s[a].c=s[a].r*s[a].h;
        s1[a].r=s[a].r;s1[a].h=s[a].h;s1[a].d=s[a].d;s1[a].c=s[a].c;
    }
    qsort(s,n,sizeof(struct area),cmp);
    ar+=s[0].d;m--;
    qsort(s1,n,sizeof(struct area),cmp1);
    for(int i=0;i<n&&m>0;i++){
        if(s1[i].r!=s[0].r&&s1[i].h!=s[0].h){ar+=s1[i].c*2;m--;}
    }
    printf("%lld",ar);
}