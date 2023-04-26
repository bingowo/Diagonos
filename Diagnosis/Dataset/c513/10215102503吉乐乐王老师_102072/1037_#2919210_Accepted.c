#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b){
    long long int x=*(long long int *)a;
    long long int y=*(long long int *)b;
    return x<y?1:-1;
}
int main()
{
    long long int n,m;scanf("%lld%lld",&n,&m);getchar();
    long long int a[1000001]={0};
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);getchar();
    }
    qsort(a,n,sizeof(a[0]),cmp);
    unsigned long long int ret=0;
    for(int i=1;i<m;i++)ret+=a[0]-a[i];
    unsigned long long int MIN=ret;
    for(int i=1;i<=n-m;i++){
        ret=ret-(a[i-1]-a[i])*(m-1)+(a[i]-a[i+m-1]);
        MIN=ret<MIN?ret:MIN;
    }
    printf("%llu",MIN);
}