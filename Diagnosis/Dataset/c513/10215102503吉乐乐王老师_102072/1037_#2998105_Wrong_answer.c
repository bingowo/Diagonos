#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b){
    return *(int*)a>*(int*)b?1:-1;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    long long int data[1001];
    for(int i=0;i<n;i++){
        scanf("%lld",&data[i]);
    }
    qsort(data,n,sizeof(data[0]),cmp);
    long long int ret=0;
    long long int now=0;
    for(int i=0;i<m-1;i++){
        now+=data[m-1]-data[i];
    }
    ret=now;
    for(int i=m;i<n;i++){
        now-=(data[i-1]-data[i-m]);
        now+=(data[i]-data[i-1])*(m-1);
        ret=now<ret?now:ret;
    }
    printf("%lld",ret);
}
