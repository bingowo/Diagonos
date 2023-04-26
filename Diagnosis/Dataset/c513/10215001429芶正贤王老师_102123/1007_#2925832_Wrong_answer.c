/*1007.非重复二进制串*/
#include<stdio.h>
void showthelen(long long int x);
int main()
{
    int T;
    scanf("%d",&T);//问题数
    int i;
    long long int input[10];
    for(i=0;i<T;i++)
    {
        scanf("%lld",&input[i]);
        printf("case #%d\n",i);
        showthelen(input[i]);
    }
    return 0;
}

void showthelen(long long int x)
{
    int binary[32],cnt[32];
    int ans=1;//目前最长非重复长度
    int i=1;
    binary[0]=x%2;
    x=x/2;
    cnt[0]=1;
    for(;i<32;i++)
    {
        binary[i]=x%2;
        x=x/2;
        if(binary[i] != binary[i-1])
        {
            cnt[i]=cnt[i-1]+1;
            ans= (ans>cnt[i]?ans:cnt[i]);
        }
        else
            cnt[i]=1;
    }
    printf("%d\n",ans);
}