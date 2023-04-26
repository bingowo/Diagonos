#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int comp(const void *p1,const void *p2){
    long long *a=(long long *)p1;
    long long *b=(long long *)p2;
    long long n1=*a,n2=*b;
    int num1=0,num2=0;
    for(int step1=0;step1<64;step1++){
        if(n1&1==1)num1++;
        if(n2&1==1)num2++;
        n1=(unsigned)n1>>1,n2=(unsigned)n2>>1;
    }
    if(num1!=num2)return num2-num1;
    else{
        if (*a>*b)return 1;
        else return -1;
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        int N=0;
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
