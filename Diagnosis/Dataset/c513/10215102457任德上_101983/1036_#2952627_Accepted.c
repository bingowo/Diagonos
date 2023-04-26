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
    long long int x1,x2,y1,y2;
    x1=m1->x>=0LL?-m1->x:m1->x;
    y1=m1->y>=0ll?-m1->y:m1->y;
    x2=m2->x>=0ll?-m2->x:m2->x;
    y2=m2->y>=0ll?-m2->y:m2->y;
    if((x1+y1)==(x2+y2)){
        if(x1==x2){
            if(y1>y2)return -1;
            else return 1;
        }
        if(x1>x2)return -1;
        return 1;
    }
    if(x1+y1>x2+y2)return 1;
    return -1;
}
unsigned long long int cal_dis(struct pot a,struct pot b){
    unsigned long long int a1,b1;
    a1=a.x>b.x?ULLONG_MAX-(unsigned long long)(b.x-a.x)+1ULL:ULLONG_MAX-(unsigned long long)(a.x-b.x)+1ULL;
    b1=a.y>b.y?ULLONG_MAX-(unsigned long long)(b.y-a.y)+1ULL:ULLONG_MAX-(unsigned long long)(a.y-b.y)+1ULL;
    return a1+b1;
}
int main(){
    int n;
    scanf("%d",&n);
    struct pot m[100];
    for(int i=0;i<n;i++){
        scanf("%lld%lld",&m[i].x,&m[i].y);
    }
    qsort(m,n,sizeof(struct pot),cmp);
    int k=1,step1=63,step2=0;
    unsigned long long int dis,h=1ULL<<63;
    while(k<n){
        dis=cal_dis(m[k],m[k-1]);
        if(dis%2ULL==0ULL&&dis!=0ULL)break;
        if(dis==0ULL);
        else {
            while(h>dis){step1--;h=1ULL<<step1;}
            step2=step1+1+step2;
        }
        h=1ULL<<63;
        step1=63;
        k++;

    }
    unsigned long long q=cal_dis(m[0],m[1]);
    if(q==0ULL&&m[0].x!=m[1].x)printf("18446744073709551616\n%d",step2);
    else printf("%llu\n%d",q,step2);
    return 0;
}