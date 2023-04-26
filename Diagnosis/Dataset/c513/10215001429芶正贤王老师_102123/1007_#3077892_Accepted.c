/*1007.非重复二进制串*/
//任意邻位不相等
#include<stdio.h>
void showthelen(long long int x);
int main()
{
    int T;
    scanf("%d",&T);//问题数
    int i;
    long long int k;
    for(i=0;i<T;i++)
    {
        scanf("%lld",&k);
        printf("case #%d:\n",i);
        showthelen(k);
    }
    return 0;
}

void showthelen(long long int x)
{
    int binary[32],cnt[32];
    int ans=1;//目前最长非重复长度
    int i;
    binary[0]=x%2;
    x=x/2;
    cnt[0]=1;
    for(i=1;x!=0;i++)
    {
        binary[i]=x%2;
        x=x/2;
        
        if(binary[i] != binary[i-1])
        {
            cnt[i] = cnt[i-1]+1;//比较前一位
            ans = (ans>cnt[i]?ans:cnt[i]);
        }
        
        else
            cnt[i]=1;
    }
    printf("%d\n",ans);
}