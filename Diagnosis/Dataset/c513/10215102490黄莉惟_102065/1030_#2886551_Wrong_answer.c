#include<stdio.h>
#include <stdlib.h>
#include<string.h>
int count(long long int m){
    int k=1;
    if(m<0){
        m=m*(-1);
    }
    while(m!=0){
        m/=10;
        k*=10;
    }
    k/=10;
    m=m/k;
    return m;
}
int cmp(const void* a,const void* b)
{  
    long long int ua=*(long long int*)a;
    long long int ub=*(long long int*)b;
    long long int a1=count(ua);
    long long int b1=count(ub);
    if(a1==b1){
        return ua<ub?-1:1;
    }else{
        return b1-a1;
    }

}
void Sort(long long int *a,int n)
{
    qsort(a,n,sizeof(unsigned),cmp);
}
int main(){
    int t,n,i,j;
    long long int a[10000];
    long long int m;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d",&n);
        for (j=0;j<n;j++) scanf("%lld",a+j);
        Sort(a,n);
        for (j=0;j<n;j++) printf("%lld%c",a[j],j!=n-1?' ':'\n');
    }
}