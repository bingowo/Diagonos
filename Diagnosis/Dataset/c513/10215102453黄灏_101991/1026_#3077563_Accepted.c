#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b){
    long long *p1=(long long *)a;
    long long *p2=(long long *)b;
    return *p1-*p2;
}

int main()
{
    int total;
    scanf("%d",&total);
    long long *p=(int*) malloc(total*sizeof(long long));
    for(int i=0;i<total;i++){
        scanf("%lld",&p[i]);
    }
    qsort(p,total,sizeof(p[0]),cmp);
    long long sum=0;
    for(int i=0;i<total/2;i++){
        sum += p[i*2+1]-p[i*2];
    }
    printf("%lld",sum);
    return 0;
}
