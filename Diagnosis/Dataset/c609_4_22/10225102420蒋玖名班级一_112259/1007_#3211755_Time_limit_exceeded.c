#include <stdio.h>
#include <stdlib.h>
int f(int n)
{
    int count=0,sign=0,a;
    if(n<0){
        n=-n-1;
        sign=1;
    }
    do{
        a=n%2;
        n/=2;
        if(a==1) count++;
    }while(n!=0);
    if(sign) return 64-count;
    return count;
}
int main()
{
    int T;scanf("%d",&T);
    long long mi;
    for(int i=0;i<T;i++)
    {

        int N;scanf("%d",&N);
        long long a[N];
        for(int j=0;j<N;j++)
            scanf("%lld",&a[j]);
        printf("case #%d:\n",i);
        if(N==1)
            printf("%lld",a[0]);
        else{
            for(int j=N-2;j>=0;j--)
            {
                for(int k=0;k<=j;k++)
                {
                    if(f(a[k])<f(a[k+1])||f(a[k])==f(a[k+1])&&a[k]>a[k+1])
                    {
                        mi=a[k];a[k]=a[k+1];a[k+1]=mi;
                    }
                }
            }
            for(int j=0;j<N;j++)
            {
                printf("%lld ",a[j]);
            }
        }
        printf("\n");
    }
    return 0;
}
