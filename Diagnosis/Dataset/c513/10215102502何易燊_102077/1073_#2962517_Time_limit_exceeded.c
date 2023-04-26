#include <stdio.h>

int num[20];

long long dfs(long long pos,long long sum,long long limit)
{
    if (pos==0&&sum%9==0) return 0;
    else if (pos==0&&sum%9!=0) return 1;
    long long res = 0;
    long long max_num = limit?num[pos]:8;
    for (int i=0;i<=max_num;i++) res += dfs(pos-1,sum+i,limit&&(i==max_num));
    return res;
}

long long part(long long x)
{
    int len = 0;
    while (x) {num[++len] = x%10; x /= 10;}
    return dfs(len,0,1);
}

int main()
{
    long long a,b; scanf("%lld %lld",&a,&b);
    printf("%lld\n",part(b)-part(a-1));
    return 0;
}