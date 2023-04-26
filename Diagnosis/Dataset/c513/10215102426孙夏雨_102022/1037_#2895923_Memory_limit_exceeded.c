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
    long long int* p2=(long long int* )malloc((n-m+1)*sizeof(long long int));;
    for(int k=0;k<=n-m;k++){
        long long int* p1=(long long int* )malloc(m*sizeof(long long int));
        for(int jj=0;jj<m;jj++) p1[jj]=*(p+k+jj);
        qsort(p1,m,sizeof(long long int),cmp);
        long long int max=*(p1);
        long long int cha=0;
        for(int kk=1;kk<m;kk++) cha+=max-*(p1+kk);
        *(p2+k)=cha;
    }
    qsort(p2,n-m+1,sizeof(long long int),cmp);
    printf("%lld",*(p2+n-m));
    return 0;
}
