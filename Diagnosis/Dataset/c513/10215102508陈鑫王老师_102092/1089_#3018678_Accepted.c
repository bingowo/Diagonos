#include<stdio.h>
#include<stdlib.h>
int wei(long long int a)
{
    int ret=0;
    while(a)
    {
        ret++;
        a=a/10;
    }
    return ret;

}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int A,B,N;
        scanf("%d %d %d",&A,&B,&N);
        int temp=1;
        for(int j=0;j<N;j++)
        {
            temp*=10;
        }
        long long int ans=1;
        for(int j=0;j<B;j++)
        {
            ans*=A;
            ans=ans%temp;
        }
        int len=wei(ans);
        printf("case #%d:\n",i);
        for(int j=0;j<(N-len);j++)
        {
            printf("0");
        }
        if(ans!=0)
        printf("%lld\n",ans);
        else printf("\n");


    }
    return 0;
}
