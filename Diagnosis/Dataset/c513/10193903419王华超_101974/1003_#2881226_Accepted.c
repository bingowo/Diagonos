#include<stdio.h>
#include<stdlib.h>

struct data
{
  long long int a;
  int number;
};

int cmp (const void *a,const void *b){
    struct data d1,d2;
    d1=*((struct data *)a);
    d2=*((struct data *)b);
    if(d1.number!=d2.number){
        return d2.number-d1.number;
    }
    else{
        if(d1.a>d2.a) return 1;
        else return -1;
    }
}
void solve(){
    struct data p[10000];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&p[i].a);
        long long mask=1;
        p[i].number=0;
        for(int t=0;t<64;t++){
            if(p[i].a&mask) p[i].number++;
            mask=mask<<1;
        }
    }
    qsort(p,n,sizeof(p[0]),cmp);
    for(int i=0;i<n;i++){
        printf("%lld%c",p[i].a,(i==n-1?'\n':' '));
    }
}
int main(){
    int T;
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++){
        printf("case #%d:\n",cas);
        solve();
    }
    return 0;
}