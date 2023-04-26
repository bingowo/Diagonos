#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        long long int a,b,N,m;
        scanf("%lld %lld %lld",&a,&b,&N);
        long long int s=1;
        m=pow(10,N);
        for(int j=1;j<=b;j++)
        {
            s=s%m;
            s*=a;
        }
        int out[20];
        for(int j=0;j<20;j++) out[j]=0;
        for(int j=0;j<N;j++)
        {
            out[19-j]=s%10;
            s/=10;
        }
        printf("case #%d:\n",i);
        int test=0;
        for(int j=20-N;j<20;j++)
        {
            printf("%d",out[j]);
        }
        printf("\n");
    }
}
