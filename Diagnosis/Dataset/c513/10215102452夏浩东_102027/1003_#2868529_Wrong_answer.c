#include <stdio.h>
#include <stdlib.h>
int cmp(const void *k1,const void *k2)
{
    long long int *p1=(long long int*)k1;
    long long int *p2=(long long int*)k2;
    int num1=0,num2=0;
    if(*p1<0) *p1=~*p1+1;
    if(*p2<0) *p2=~*p2+1;
    while(*p1>0){
        if(*p1%2==1) num1++;
        *p1=*p1/2;
    }
    while(*p2>0){
        if(*p2%2==1) num2++;
        *p2=*p2/2;
    }
    if(num1==num2)
    {
        if((long long int*)k1>(long long int*)k2) return 1;
        else return -1;
    }
    else return num2-num1;
}
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    for(int i=0;i<cnt;i++)
    {
        int num=0;
        scanf("%d",&num);
        long long int *L = (long long int*)malloc(sizeof(long long int)*num);
        for(int t=0;t<num;t++)
        {
            scanf("%lld",&L[t]);
        }
        qsort(L,num,sizeof(int),cmp);
        printf("case #%d:\n",i);
        for(int i=0;i<num;i++)
        {
            if(i==num-1) printf("%d",L[i]);
            else printf("%d ",L[i]);
        }
    }
    return 0;
}