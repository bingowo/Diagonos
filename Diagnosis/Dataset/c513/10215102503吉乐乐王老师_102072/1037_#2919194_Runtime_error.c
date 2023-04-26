#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
unsigned long long int mina(unsigned long long int a,unsigned long long int b){
    return a<b?a:b;
}
int cmp(const void *a,const void *b){
    long long int x=*(long long int *)a;
    long long int y=*(long long int *)b;
    return x<y?1:-1;
}
int main()
{
    long long int n,m;scanf("%lld %lld\n",&n,&m);
    long long int a[100000]={0};
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);getchar();
    }
    qsort(a,n,sizeof(a[0]),cmp);
    long long int ret=0;
    for(int i=1;i<m;i++)ret+=a[0]-a[i];
    long long int MIN=ret;
    for(int i=1;i<=n-m;i++){
        ret=ret-(a[i-1]-a[i])*(m-1)+(a[i]-a[i+m-1]);
        MIN=ret<MIN?ret:MIN;
    }
    printf("%lld",MIN);
}