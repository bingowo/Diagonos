#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
struct pot{
    long long int x,y;

};
int cmp(const void *a,const void *b){
    struct pot *m1,*m2;
    m1=(struct pot *)a;
    m2=(struct pot *)b;
    unsigned long long int x1,x2,y1,y2;
    x1=m1->x>=0LL?m1->x:ULLONG_MAX-(unsigned long long)(m1->x)+1ULL;
    y1=m1->y>=0ll?m1->y:ULLONG_MAX-(unsigned long long)(m1->y)+1ULL;
    x2=m2->x>=0ll?m2->x:ULLONG_MAX-(unsigned long long)(m2->x)+1ULL;
    y2=m2->y>=0ll?m2->y:ULLONG_MAX-(unsigned long long)(m2->y)+1ULL;
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
unsigned long long int cal_dis(struct pot a,struct pot b){
    unsigned long long int x1,y1,x2,y2;
    x1=a.x>0LL?a.x:LLONG_MAX-(unsigned long long)(a.x)+1ULL;
    x2=b.x>0LL?b.x:LLONG_MAX-(unsigned long long)(b.x)+1ULL;
    y1=a.y>0LL?a.y:LLONG_MAX-(unsigned long long)(a.y)+1ULL;
    y2=b.y>0LL?b.y:LLONG_MAX-(unsigned long long)(b.y)+1ULL;
    unsigned long long int a1,b1;
    a1=x1>x2?x1-x2:x2-x1;
    b1=y1>y2?y1-y2:y2-y1;
    return a1+b1;
}
unsigned long long int Pow(unsigned long long int a,int n){
    if(n==0)return 1uLL;
    if(n==1)return a;
    unsigned long long int b=Pow(a,n/2);
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
    int k=1,step1=0,step2=0;
    unsigned long long x4=m[0].x>0?m[0].x:-m[0].x;
    unsigned long long y4=m[0].y>0?m[0].y:-m[0].y;
    unsigned long long int dis=x4+y4;
    while(k<n){
        if(dis%2LLu==0uLL)break;
        else{
            while(Pow(2LL,step1)<dis)step1++;
                step2+=step1;
                step1=0;

          }
        dis=cal_dis(m[k],m[k-1]);
        k++;
    }
    printf("%llu\n%d\n",cal_dis(m[0],m[1]),step2);
    return 0;
}