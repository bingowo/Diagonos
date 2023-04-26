#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    int R=2333,k=0;
    for(int i=0;i<T;i++)
    {
        long long n;
        int a[30000003];
        scanf("%lld",&n);
        do{
            long long r=n%R;
            a[k++]=r;
            n=n/R;
        }while(n);
    for(int j=k-1;j>=0;j--) printf("%d ",a[j]);
    printf("\n");
    k=0;
    }
    return 0;
}
