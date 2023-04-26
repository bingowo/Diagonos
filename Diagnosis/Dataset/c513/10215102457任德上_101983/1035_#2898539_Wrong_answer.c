#include<stdio.h>
#include<malloc.h>
struct cylinder{
    int r;
    int h;
};
int cmp1(const void *a,const void *b){
    struct cylinder *m1,*m2;
    m1=(struct cylinder *)a;
    m2=(struct cylinder *)b;
    return m2->r-m1->r;

}
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
    qsort(a,n,sizeof(struct cylinder),cmp1);
    qsort(a+1,n-1,sizeof(struct cylinder),cmp2);
    int s=a->r*a->r;
    for(int i=0;i<m;i++){s+=2*(a+i)->r*(a+i)->h;}
    printf("%d",s);
    free(a);
    return 0;
}