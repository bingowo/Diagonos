#include <stdio.h>
#include <string.h>
struct data{
   long long int R;
   long long int H;
   long long int sum1;
   long long int sum2;
};

int cmp1(const void* a,const void* b){
    struct data x=*(struct data*)a;
    struct data y=*(struct data*)b;
    return x.sum1<y.sum1;
}

int cmp2(const void* a,const void* b){
    struct data x=*(struct data*)a;
    struct data y=*(struct data*)b;
    return x.sum2<y.sum2;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    struct data p[1000];
    for(int i=0;i<n;i++){
        scanf("%lld%lld",&p[i].R,&p[i].H);
        p[i].sum1=2*(p[i].R)*(p[i].H);
        p[i].sum2=(p[i].R)*(p[i].R);
    }
    qsort(p,n,sizeof(p[0]),cmp1);
    qsort(p,m,sizeof(p[0]),cmp2);
    long long int squre=p[0].sum2;
    for(int i=0;i<m;i++){
        squre+=p[i].sum1;
    }
    printf("%lld",squre);
}
