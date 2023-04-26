#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int r,h;
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
        scanf("%d%d",&data[i].r,&data[i].h);
    }
    qsort(data,n,sizeof(node),cmp);
    int ret=0;
    for(int i=0;i<n;i++){
        if(i+m>n)break;
        int cur=0;
        for(int j=i;j<i+m;j++){
            cur+=2*data[j].r*data[j].h;
        }
        cur+=data[i+m-1].r*data[i+m-1].r;
        ret=cur>ret?cur:ret;
    }
    printf("%d",ret);
}
