#include <stdio.h>
#include <math.h>

int main() {
    int T;
    scanf("%d",&T);
    long long A,B,count;
    int N;
    for(int i=0;i<T;i++)
    {
        scanf("%lld%lld%d",&A,&B,&N);
        count = pow(10,N);
        long long a=A;
        for(int j=0;j<B-1;j++)
        {
            A%=count;
            A*=a;
        }
        A%=count;
        printf("case #%d:\n%0*lld\n",i,N,A);
    }
    return 0;
}
