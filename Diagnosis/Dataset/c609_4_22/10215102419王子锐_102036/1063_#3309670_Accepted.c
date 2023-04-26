#include <stdio.h>

typedef long long LL;

LL Num[51]={0,1,2,4,8};

LL T(LL n)
{
    if (n==0) return 0;
    else if (n==1) return 1;
    else if(n==2) return 2;
    else if (n==3) return 4;
    else if (n==4) return 8 ;
    else
    {
        LL t1 =(Num[n-1]==0?T(n-1):Num[n-1]);
        LL t2 =(Num[n-2]==0?T(n-2):Num[n-2]);
        LL t3 =(Num[n-3]==0?T(n-3):Num[n-3]);
        LL t4 =(Num[n-4]==0?T(n-4):Num[n-4]);
        return Num[n]=t1+t2+t3+t4;
    }

}

int main()
{
    int t;
    LL n;
    scanf("%d",&t);

    for (int i=0;i<t;i++)
    {
        scanf("%lld",&n);
        printf("case #%d:\n",i);
        printf("%lld\n",T(n));
    }
    return 0;
}