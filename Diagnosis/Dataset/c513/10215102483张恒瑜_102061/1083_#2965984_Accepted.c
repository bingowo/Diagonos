#include<stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        int n;
        scanf("%d",&n);
        long long cnt2=0,cnt5=0;
        for(int i=1;i<=n;i++)
        {
            int tmp=i;
            while(tmp%2==0) {tmp/=2;cnt2++;}
            while(tmp%5==0) {tmp/=5;cnt5++;}
        }
        printf("case #%d:\n%lld\n",t,cnt2>cnt5 ? cnt5:cnt2);
    }
    return 0;
}