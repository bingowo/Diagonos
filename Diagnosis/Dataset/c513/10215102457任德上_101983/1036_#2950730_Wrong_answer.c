#include<stdio.h>
#include<stdlib.h>
#include<math.h>
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
long long int cal_dis(struct pot a,struct pot b){
    long long int x1=a.x-b.x;
    long long int y1=a.y-b.y;
    x1=x1>0LL?x1:-x1;
    y1=y1>0LL?y1:-y1;
    return x1+y1;
}
long long int Pow(long long int a,int n){
    if(n==0)return 1LL;
    if(n==1)return a;
    long long int b=Pow(a,n/2);
    b=b*b;
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
    int k=0,step1=0,step2=0;
    long long int dis=abs(m[0].x)+abs(m[0].y);
    while(k<n){
        if(Pow(2LL,step1)<=dis&&Pow(2LL,step1+1)>dis){
            k++;
            dis=cal_dis(m[k],m[k-1]);
            step1=-1;
        }
        else if(dis%2LL==0LL)break;
        step2++;
        step1++;
    }
    printf("%lld\n%d",cal_dis(m[0],m[1]),step2);
    return 0;
}