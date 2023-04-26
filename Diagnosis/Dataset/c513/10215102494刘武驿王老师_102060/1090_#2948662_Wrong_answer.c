#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        double m,N;
        N=n;
        m=N*log10(N);
        m=m-(int)m;
        m=pow(10,m);
        n=(int)m;
        printf("%d\n",n);
    }
    return 0;
}
