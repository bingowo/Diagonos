#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        double m,N;
        int j;
        N=n;
        m=N*log10(N);
        m=m-(int)m;
        m=pow(10,m);
        j=(int)m;
        printf("%d\n",j);
    }
    return 0;
}
