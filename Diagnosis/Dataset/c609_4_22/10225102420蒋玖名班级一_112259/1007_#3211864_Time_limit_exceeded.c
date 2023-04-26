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
void sort(long long a[],int N)
{
    long long temp;
    for(int i=N-2;i>=0;i--)
    {
        for(int k=0;k<=i;k++)
        {
            if(f(a[k])<f(a[k+1])||f(a[k])==f(a[k+1])&&a[k]>a[k+1])
            {
                temp=a[k];a[k]=a[k+1];a[k+1]=temp;
            }
        }
    }
    for(int i=0;i<N;i++)
        printf("%lld ",a[i]);
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
            sort(a,N);
        }
        printf("\n");
    }
    return 0;
}
