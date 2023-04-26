#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long long comp(const void *e1,const void *e2){
    long long* p1 = (long long* )e1;
    long long* p2 = (long long* )e2;
    long long num1=0,num2=0;
    long long len1=*p2,len2=*p1;
    for(int i=0;i<64;i++){
        if(len1&1==1)num2++;
        if(len2&1==1)num1++;
        len1>>1,len2>>1;
    }
    if(num1!=num2)return num1-num2;
    else return (long long* )e1-(long long* )e2;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        int N;
        scanf("%d",&N);
        long long a[N];
        for(int n=0;n<N;n++){
            scanf("%lld",&a[n]);
        }
        qsort(a,N,sizeof(long long),comp);
        for(int m=0;m<N-1;m++){
            printf("%lld ",a[m]);
            }
        printf("%lld\n",a[N-1]);
    }
    return 0;
}