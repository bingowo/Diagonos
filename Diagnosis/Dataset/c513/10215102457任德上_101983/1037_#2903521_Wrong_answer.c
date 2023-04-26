#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int cmp(const void *a,const void *b){
    long long int m1,m2;
    m1=*(long long int *)a;
    m2=*(long long int *)b;
    if(m1>m2)return 1;
    else return -1;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    long long int *a,min=0,k0,p=0,k;
    a=(long long int*)malloc(n*sizeof(long long int));
    for(int i=0;i<n;i++)scanf("%lld",&a[i]);
    qsort(a,n,sizeof(long long int),cmp);
    for(int i=0;i<m;i++)min+=a[m-1]-a[i];
    k0=min;
    for(int i=m;i<n;i++){
        k=k0+(m-1)*(a[i]-a[i-1])-a[i-1]+a[i-m];
        if(k<min)min=k;
    }
    printf("%lld",min);
}