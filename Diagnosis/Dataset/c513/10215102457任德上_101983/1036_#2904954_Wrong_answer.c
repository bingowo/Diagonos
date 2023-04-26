#include<stdio.h>
struct pot{
    long long int x,y;
};
int cmp(const void *a,const void *b){
    struct pot *m1,*m2;
    m1=(struct pot *)a;
    m2=(struct pot *)b;
    long long int x1,x2,y1,y2;
    x1=m1->x>=0ll?m1->x:-m1->x;
    y1=m1->y>=0ll?m1->y:-m1->y;
    x2=m2->x>=0ll?m2->x:-m2->x;
    y2=m2->y>=0ll?m2->y:-m2->y;
    if((x1+y1)==(x2+y2))return x1-x2;
    return (y2+x2-x1-y1);
}
int main(){
    int n;
    scanf("%d",&n);
    struct pot *m;
    m=(struct pot*)malloc(n*sizeof(struct pot));
    for(int i=0;i<n;i++){
        scanf("%lld %lld",&(m+i)->x,&(m+i)->y);
    }
    qsort(m,n,sizeof(struct pot),cmp);
    




}