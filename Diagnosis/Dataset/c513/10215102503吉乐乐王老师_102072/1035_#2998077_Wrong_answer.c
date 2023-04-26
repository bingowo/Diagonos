#include<stdio.h>
#include<stdlib.h>
typedef struct{
    long long int r,h;
}node;
int cmp(const void *a,const void*b){
    node x=*(node*)a,y=*(node*)b;
    if(x.r==y.r)return x.h<y.h?1:-1;
    return x.r<y.r?1:-1;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    node data[1001];
    for(int i=0;i<n;i++){
        scanf("%lld%lld",&data[i].r,&data[i].h);
    }
    qsort(data,n,sizeof(node),cmp);
    long long int ret=0;
    for(int i=0;i<n;i++){
        if(i+m>n)break;
        long long int cur=0;
        for(int j=i;j<i+m;j++){
            cur+=2*data[j].r*data[j].h;
        }
        cur+=data[i].r*data[i].r;
        ret=cur>ret?cur:ret;
    }
    printf("%lld",ret);
}
