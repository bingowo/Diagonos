#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct cylinder{
    long long int r;
    long long int h;
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
int cmp2(const void *a,const void *b){
    struct cylinder *m1,*m2;
    m1=(struct cylinder *)a;
    m2=(struct cylinder *)b;
    long long int r1,r2,h1,h2;
    r1=(long long int)m1->r;
    r2=(long long int)m2->r;
    h1=(long long int)m1->h;
    h2=(long long int)m2->h;
    if(r1*h1>r2*h2)return 1;
    return -1;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    struct cylinder *a,*b;
    a=(struct cylinder *)malloc(n*sizeof(struct cylinder));
    for(int i=0;i<n;i++)scanf("%lld %lld",&(a+i)->r,&(a+i)->h);
    qsort(a,n,sizeof(struct cylinder),cmp1);
    long long int s,max=0;
    for(int i=m-1;i<n;i++){
        qsort(a,i,sizeof(struct cylinder),cmp2);
        s=(a+i)->r*(a+i)->r;
        for(int k=i-m+1;k<=i;k++)s=s+2*(a+k)->r*(a+k)->h;
        if(s>max)max=s;
    }
    printf("%lld",max);
    free(a);
    return 0;
}