#include<stdio.h>
#include<stdlib.h>
#include<math.h>
long long int mina(long long int a,long long int b){
    return a<b?a:b;
}
int cmp(const void *a,const void *b){
    long long int x=*(long long int *)a;
    long long int y=*(long long int *)b;
    return x>y?1:-1;
}
int main(){
    long long int n,m;scanf("%lld %dll",&n,&m);getchar();
    long long int a[1000000];
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);getchar();
    }
    qsort(a,n,sizeof(a[0]),cmp);
    long long int ret[1000000]={0};int idx=0;
    for(int i=0;i+m-1<n;i++){
        int tm=a[i+m-1];
        for(int j=i+m-2;j>=i;j--){
            ret[idx]+=tm-a[j];
        }
        idx++;
    }
    long long int res=ret[0];
    for(int i=0;i<idx;i++){
        res=mina(ret[i],res);
    }
    printf("%lld",res);
}