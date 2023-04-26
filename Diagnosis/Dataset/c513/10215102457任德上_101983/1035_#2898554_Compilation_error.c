#include<stdio.h>
#include<malloc.h>
struct cylinder{
    int r;
    int h;
};
int cmp2(const void *a,const void *b){
    struct cylinder *m1,*m2;
    m1=(struct cylinder *)a;
    m2=(struct cylinder *)b;
    return m2->r*m2->h-m1->r*m1->h;

}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    struct cylinder *a,*b;
    a=(struct cylinder *)malloc(n*sizeof(struct cylinder));
    for(int i=0;i<n;i++)scanf("%d %d",&(a+i)->r,&(a+i)->h);
    qsort(a,n,sizeof(struct cylinder),cmp2);
    long long int s=a->r*a->r;
    for(int i=0;i<m;i++){s+=2LL*（long long int)(a+i)->r*(long long int)(a+i)->h;}
    printf("%lld",s);
    free(a);
    return 0;
}