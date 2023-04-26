#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct cylinder{
    int r;
    int h;
};
int cmp1(const void *a,const void *b){
    struct cylinder *m1,*m2;
    m1=(struct cylinder *)a;
    m2=(struct cylinder *)b;
    long long int r1,r2,h1,h2;
    r1=(long long int)m1->r;
    r2=(long long int)m2->r;
    if(r1>r2)return 1;
    return -1;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    struct cylinder *a,*b;
    a=(struct cylinder *)malloc(n*sizeof(struct cylinder));
    for(int i=0;i<n;i++)scanf("%d %d",&(a+i)->r,&(a+i)->h);
    qsort(a,n,sizeof(struct cylinder),cmp1);
    long long int s,k,max=(a+i)->r*(a+i)->r;
    for(int i=0;i<m;i++)max+=2*(a+i)->r*(a+i)->h;
    s=max;
    for(int i=m;i<n;i++,k--){
        k=2*(a+i)->r*(a+i)->h-2*(a+i-m)->r*(a+i-m)->h+(a+i)->r*(a+i)->r-(a+i-1)->r*(a+i-1)->r;
        s=s+k;
        if(s>max)max=s;
        
    }
    printf("%lld",max);
    free(a);
    return 0;
}