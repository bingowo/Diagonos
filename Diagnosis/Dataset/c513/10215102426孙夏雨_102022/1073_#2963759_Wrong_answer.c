#include <stdio.h>
#include <stdlib.h>

long long int cifang(int x,int n)
{
    long long int ans=1;
    for(int i=0;i<n;i++) ans*=x;
    return ans;
}

long long int jiushi(long long int x)
{
    long long int ans=0;
    int i=0,yushu=0;
    while(x>0){
        yushu=x%10;
        ans+=(yushu*cifang(9,i));
        i++;
        x/=10;
    }
    return ans;
}

long long int shijiu(long long int x)
{
    long long int ans=0;
    int an[20],num=0;
    while(x>0){
        an[num]=x%9;
        x/=9;
        num++;
    }
    for(int i=0;i<num;i++) ans+=(an[i]*cifang(10,i));
    return ans;
}

int main()
{
    long long int a=0,b=0;
    scanf("%lld %lld",&a,&b);
    long long int wu9=0;
    long long int zuihou=0;
    wu9=jiushi(b)-jiushi(0)+1;
    wu9-=(jiushi(a)-jiushi(0));
    zuihou=jiushi(b);
    long long int zushu=wu9/9;
    long long int n=wu9%9;
    long long int ans=zushu*8;
    for(int j=1;j<=n;j++){
        long long int yaozhuan=zuihou-j;
        long long int zhuanhou=shijiu(yaozhuan);
        if(zhuanhou%9!=0) ans++;
    }
    printf("%lld\n",ans);
    return 0;
}
