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
    long long int *a,min,p=0;
    a=(long long int*)malloc(n*sizeof(long long int));
    for(int i=0;i<n;i++)scanf("%lld",&a[i]);
    qsort(a,n,sizeof(long long int),cmp);
    min=a[m-1]-a[0];
    for(int i=m;i<n;i++){
        int k=a[i]-a[i-m+1];
        if(k<min){min=k,p=i-m+1;}
    }
    long long int sum=0;
    for(int k=0;k<m-1;k++)sum+=a[p+m-1]-a[k+p];
    printf("%lld",sum);
}