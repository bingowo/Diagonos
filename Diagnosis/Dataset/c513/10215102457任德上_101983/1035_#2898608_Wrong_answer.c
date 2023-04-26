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
    h1=(long long int)m1->h;
    h2=(long long int)m2->h;
    if((r1*r1+2*r1*h1)>(r2*r2+2*r2*h2))return -1;
    return 1;


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
    if(r1*h1>r2*h2)return -1;
    return 1;

}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    struct cylinder *a,*b;
    a=(struct cylinder *)malloc(n*sizeof(struct cylinder));
    for(int i=0;i<n;i++)scanf("%d %d",&(a+i)->r,&(a+i)->h);
    qsort(a,n,sizeof(struct cylinder),cmp1);
    qsort(a+1,n-1,sizeof(struct cylinder),cmp2);
    long long int s=a->r*a->r;
    for(int i=0;i<m;i++){s+=2LL*(long long int)(a+i)->r*(long long int)(a+i)->h;}
    printf("%lld",s);
    free(a);
    return 0;
}