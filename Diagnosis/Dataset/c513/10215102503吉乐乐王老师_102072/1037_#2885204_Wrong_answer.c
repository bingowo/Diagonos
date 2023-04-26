#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b){
    long long int x=*(long long int *)a;
    long long int y=*(long long int *)b;
    return x>y?1:-1;
}
int main(){
    long long int n,m;scanf("%LLD,%LLD",&n,&m);getchar();
    long long int a[1000000];
    for(int i=0;i<n;i++){
        scanf("%LLD",&a[i]);getchar();
    }
    qsort(a,n,sizeof(a[0]),cmp);
    long long int ret[100000]={0};int idx=0;
    for(int i=0;i+2<n;i++){
        ret[idx]=(a[i+2]-a[i+1])+(a[i+1]-a[i]);
    }
    long long int res=0;
    for(int i=0;i<idx;i++){
        res+=ret[i];
    }
    printf("%LLD",res);
}
