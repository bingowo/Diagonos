#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void*b){
    long long int m=*(long long int*)a;
    long long int n=*(long long int*)b;
    return m>n;
}
int main(){
    long int n,m;
    scanf("%ld%ld",&n,&m);
    long long int p[n];
    for(long int i=0;i<n;i++){
        scanf("%lld",p[i]);
    }
    qsort(p,n,sizeof(p[0]),cmp);
    long long int sum=0;
    for(long int i=0;i<m;i++){
        sum=sum+p[m-1]-p[i];
    }
    long long int min=sum;
    for(long int i=m;i<n;i++){
        sum=sum+p[i-m]-p[i-1]+(m-1)*(p[i]-p[i-1]);
        if(sum<min)min=sum;
    }
    printf("%lld",min);
}