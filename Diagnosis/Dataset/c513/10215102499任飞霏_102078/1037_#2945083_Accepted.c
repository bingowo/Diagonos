#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b)
{
    long long x=*((long long*)a);
    long long y=*((long long*)b);
    if(x>y)return -1;
    else
        return 1;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    long long *num;
    num =(long long*)malloc(1000000*sizeof(long long));
    long long *cut;
    cut =(long long*)malloc(1000000*sizeof(long long));
    for(int i=0;i<n;i++){
        scanf("%lld",&num[i]);
    }
    qsort(num,n,sizeof(long long),cmp);
    for(int i=0;i<n-1;i++){
        cut[i]=num[i]-num[i+1];
    }
    long long  tmp=0;
    //最大m个数
    for(int i=0;i<m-1;i++){
        tmp+=cut[i]*(m-i-1);
    }
    long long min=tmp;
    for(int i=0;i<n-m;i++){
        tmp-=cut[i]*(m-1);
        tmp+=(num[i+1]-num[i+m]);
        if(tmp<min)min=tmp;
    }
    printf("%lld",min);
    return 0;
}
