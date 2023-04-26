#include<string.h>
#include<stdio.h>
#include<stdlib.h>
typedef long long int lli;
lli myabs(lli a,lli b){
    if(a-b<0)return b-a;
    return a-b;
}
int cmp(const void *a,const void *b){
    return *(lli*)a-*(lli*)b;
}
int main(){
    int t;scanf("%d",&t);
    lli *n=(lli*)malloc(sizeof(lli)*t);
    for(int i=0;i<t;i++){
        scanf("%lld",(n+i));
    }
    qsort(n,t,sizeof(lli),cmp);
    lli ret=0;
    for(int i=1;i<t;i+=2){
        ret+=myabs(n[i],n[i-1]);
    }
    printf("%lld",ret);
}