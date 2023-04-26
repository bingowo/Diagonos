#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define M 1000000007
long long ans=1;
char s[1000005];

int main()
{
    scanf("%s",s);
    //更好的分布方式
    //用计数器分别计算
    for(int i=0;s[i];i++)
    {
        int cnt=1;
        if(i!=0 && s[i-1]!=s[i]) //前面
            cnt++;
        if(s[i+1]!=0 && s[i+1]!=s[i]) //后面
            cnt++;
        if(i!=0 && s[i+1]!=0 && s[i+1]==s[i-1] && cnt==3) //特殊情况
            cnt--;
        ans=ans*cnt%M;
    }
    printf("%lld\n",ans);
    return 0;
}
//关键是计数的方式要简洁高效
