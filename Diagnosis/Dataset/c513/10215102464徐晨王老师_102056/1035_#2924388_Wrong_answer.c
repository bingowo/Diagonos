#include <stdio.h>
#include <string.h>
struct data{
   long long int R;
   long long int H;
   long long int sum;
};

int cmp(const void* a,const void* b){
    struct data x=*(struct data*)a;
    struct data y=*(struct data*)b;
    return x.sum<y.sum;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    struct data p[1000];
    for(int i=0;i<n;i++){
        scanf("%lld%lld",&p[i].R,&p[i].H);
        p[i].sum=(p[i].R)*(p[i].R)+2*(p[i].R)*(p[i].H);
    }
    qsort(p,n,sizeof(p[0]),cmp);
    long long int squre=p[0].sum;
    for(int i=1;i<m;i++){
        squre+=2*(p[i].R)*(p[i].H);
    }
    printf("%lld",squre);
}
