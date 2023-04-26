#include <stdio.h>
#include <stdlib.h>
int cmp(const void* a,const void* b){
        long long n1=*((long long *)a),n2=*((long long*)b);
        if(n1>n2)return 1;
        else return -1;
}
int main()
{
    long long n;scanf("%lld",&n);
    long long num[n],ans=0;
    for(int i=0;i<n;i++)
            scanf("%lld",&num[i]);
    qsort(num,n,sizeof(num[0]),cmp);
    for(int i=0;i<n/2;i++){
        ans+=num[i*2+1]-num[i*2];
    }
    printf("%lld\n",ans);
}