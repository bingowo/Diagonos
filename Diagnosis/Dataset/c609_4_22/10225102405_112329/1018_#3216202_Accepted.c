#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
    int* _a=(int*)a;
    int* _b=(int*)b;
    return *_a>*_b;
}
int main()
{
    int T,a[1000000],i,sum=0;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d",&a[i]);
    }
    qsort(a,T,sizeof(a[0]),cmp);
    for(i=0;i<T;i+=2){
        sum+=a[i+1]-a[i];
    }
    printf("%d",sum);
}
