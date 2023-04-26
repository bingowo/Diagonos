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
    return x>y?1:-1;
}
int main()
{
    long long int n,m;scanf("%lld %lld\n",&n,&m);
    long long int a[1000000]={0};
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);getchar();
    }
    qsort(a,n,sizeof(a[0]),cmp);
    unsigned long long int ret=ULLONG_MAX;
    for(int i=0;i+m-1<n;i++){
        long long int ml=a[i+m-1];unsigned long long int temp=0;
        for(int j=i+m-2;j>=i;j--){
            temp+=ml-a[j];
        }
        ret=mina(ret,temp);
    }
    printf("%llu",ret);
}