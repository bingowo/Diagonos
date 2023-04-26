#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d",&n);
    while(n)
    {
        double m,N;
        int j;
        N=n;
        m=N*log10(N);
        m=m-(int)m;
        m=pow(10,m);
        j=(int)m;
        printf("%d\n",j);
        scanf("%d",&n);
    }
    return 0;
}
