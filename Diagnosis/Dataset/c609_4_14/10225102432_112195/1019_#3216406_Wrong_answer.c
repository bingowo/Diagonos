#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a , const void* b){
    int*a1=(int*)a;
    int*b1=(int*)b;
    int t1=*a1,t2=*b1,flag;
    if(t1>t2) flag=1;
    else flag=-1;
    if(t1<0) t1=-t1;
    if(t1<0) t2=-t2;
    int sum1=0,sum2=0;
    while(t1>0){
        sum1++;
        t1/=10;
    }
    while(t2>0){
        sum2++;
        t2/=10;
    }
    if (sum1<sum2) return 1;
    else if(sum1==sum2 && flag) return 1;
    else return -1;
}

int main()
{   int a[1000002],n=0,i;
    while(scanf("%d",&a[n++])!=EOF);
    qsort(a,n,4,cmp);
    for(i=0;i<n-1;i++)
        printf("%d ",a[i]);
    return 0;
}
