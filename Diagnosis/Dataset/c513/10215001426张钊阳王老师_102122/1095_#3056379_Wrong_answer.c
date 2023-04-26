#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    long long tim4(int t);
    //首先要转二进制
    char s0[1000];
    scanf("0x%s",s0);
    int s[1000];
    int l0=strlen(s0),l;//l0作为十六进制的长度 l作为二进制的长度
    for(int g=0;g<l0;g++)
    {
        if(s0[g]>='0'&&s0[g]<='9')
        {
            s[g]=s0[g]-'0';
        }
        else if(s0[g]>='A'&&s0[g]<='Z')
        {
            s[g]=s0[g]-'A'+10;
        }
    }
    int t[5000]={0};
    int j=4*l0-1;
    l=4*l0;
    for(int i=l0-1;i>=0,j>=0;i--)
    {
        for(int k=0;k<4;k++)
        {
            t[j-k]=s[i]%2;
            s[i]/=2;
            if(s[i]==0) break;
        }
        j-=4;
    }
    //这里检测一下二进制是否正确
    //for(int p=0;p<l;p++) printf("%d",t[p]);
    //之后将二进制转化为-1+i进制 数组t[]是二进制
    long long a=0,b=0;
    for(int j=l-1;j>=0;j--)
    {
        if(t[j]==0) continue;
        else {
            int times=(l-j-1)/4,num=(l-j-1)%4;
            long long temp,base;
            if(num==0) base=1;
            else if(num==1) base=-1;
            else if(num==2) base=0;
            else if(num==3) base=2;
            temp=base*tim4(times);
            a+=temp;
            if(num==0) base=0;
            else if(num==1) base=1;
            else if(num==2) base=-2;
            else if(num==3) base=2;
            temp=base*tim4(times);
            b+=temp;
        }
    }
    if(a!=0&&b==0) printf("%lld",a);
    else if(a==0&&b!=0) printf("%lldi",b);
    else if(a==0&&b==0) printf("0");
    else if(a!=0&&b>0) printf("%lld+%lldi",a,b);
    else if(a!=0&&b<0) printf("%lld%lldi",a,b);
    return 0;
}
long long tim4(int t)
{
    long long sum=1;
    for(int j=0;j<t;j++)
    {
        sum*=(-4);
    }
    return sum;
}
