#include<stdio.h>
#include<stdlib.h>
struct pot{
    long long int x,y;
    long long int distance;
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
    m1->distance=x1+y1;
    m2->distance=x2+y2;
    if((x1+y1)==(x2+y2)){
        if(x1==x2){
            if(y1>y2)return 1;
            else return -1;
        }
        if(x1>x2)return 1;
        return -1;
    }
    if(x1+y1>x2+y2)return -1;
    return 1;
}
long long int Pow(long long int a,int n){
    if(n==0)return 1;
    if(n==1)return a;
    long long int b=Pow(a,n/2);
    if(n%2)b*=a;
    return b;
}
int main(){
    int n;
    scanf("%d",&n);
    struct pot m[100];
    for(int i=0;i<n;i++){
        scanf("%lld%lld",&m[i].x,&m[i].y);
    }
    qsort(m,n,sizeof(struct pot),cmp);
    int k=0,step=0;
    long long int dis=m[0].distance;
    while(k<n){
        if(Pow(2LL,step)>dis||((dis%2LL)==1LL&&k>0)||((dis%2LL==0LL)&&k==0))break;
        if(Pow(2LL,step)<=dis&&Pow(2LL,step+1)>dis){
            dis=m[k].distance-m[k-1].distance;
            k++;
        }
        step++;
    }
    printf("%lld\n%d",m[0].distance-m[1].distance,step);
    return 0;
}