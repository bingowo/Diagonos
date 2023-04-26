#include<stdio.h>
#include<stdlib.h>
typedef struct{
    long long int r,h;
}node;
int cmp(const void *a,const void*b){
    node x=*(node*)a,y=*(node*)b;
    if(x.r*x.h==y.h*y.r)return x.r<y.r?1:-1;
    return x.r*x.h<y.h*y.r?1:-1;
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
        long long int cur=data[i].r*data[i].r+2*data[i].r*data[i].h;
        int idx=1;
        int pre=data[i].r;
        for(int j=0;j<n;j++){
            if(j!=i&&data[j].r<=pre){
                cur+=2*data[j].h*data[j].r;
                pre=data[j].r;
                idx++;
            }
            if(idx==m){
                ret=cur>ret?cur:ret;
                break;
            }
        }
    }
    printf("%lld",ret);
}
