#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p3,const void* p4)
{
    long long int* p1=(long long int* )p3;
    long long int* p2=(long long int* )p4;
    if((*p1)<(*p2)) return 1;
    else return -1;
}

int main()
{
    int n=0,m=0;
    scanf("%d %d",&n,&m);
    long long int* p=(long long int* )malloc(n*sizeof(long long int));
    for(int i=0;i<n;i++) scanf("%lld",(p+i));
    qsort(p,n,sizeof(long long int),cmp);
    long long int min=0,sum=0;
    for(int k=0;k<=n-m;k++){
        long long int max=*(p+k);
        long long int cha=(m-1)*max;
        if(k==0) {
            for(int kk=1,ww=m-1;kk<ww;kk++,ww--) sum+=*(p+k+ww)+*(p+k+kk);
            if((m-1)%2!=0) sum+=*(p+k+m/2);
        }
        else sum=sum+(*(p+k+m-1))-(*(p+k));
        if(k==0) min=cha-sum;
        else min=min<cha-sum?min:cha-sum;
    }
    printf("%lld",min);
    return 0;
}
