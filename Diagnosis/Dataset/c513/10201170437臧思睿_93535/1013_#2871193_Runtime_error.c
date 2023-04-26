#include <stdio.h>
#include <string.h>
#include <math.h>
typedef long long int ll;

ll gcd(ll a,ll b)
{
    if(a<0){a=-a;}
    if(a>b)
    {
        ll temp=a;
        a=b;
        b=temp;
    }
    if(b%a==0){return a;}
    else{return gcd(b%a,a);}
}

ll poww(ll x,int y)
{
    ll r=1;
    for(int i=0;i<y;i++)
    {
        r*=x;
    }
    return r;
}

int main()
{
    char s[15];
    memset(s,0,sizeof(int));
    scanf("%s",s);
    s[strlen(s)+1]='\0';
    int j;
    for(j=0;j<strlen(s);j++)//定位'.',j就是小数点的下标
    {
        if(s[j]=='.'){break;}
    }
    ll sum=0;
    for(int i=j-1;i>=0;i--)
    {
        if(s[i]=='1')
        {
            sum+=poww(3,j-i-1);
        }
        if(s[i]=='2')
        {
            sum-=poww(3,j-i-1);
        }
    }
    if(j==strlen(s)){printf("%lld",sum);return 0;}
    ll sum1=0;//现在用sum1来存储分母
    for(int i=strlen(s)-1;i>j;i--)
    {
        if(s[i]=='1')
        {
            sum1+=poww(3,strlen(s)-i-1);
        }
        if(s[i]=='2')
        {
            sum1-=poww(3,strlen(s)-i-1);
        }
    }
    ll x=poww(3,strlen(s)-j-1);//x用来存储分母
    ll y=sum*x+sum1;
    sum=y/x;
    sum1=(y>0?y:-y)%x;
    sum1/=gcd(sum1,x);x/=gcd(sum1,x);
    if(sum==0)
    {
        if(y<0){printf("-");}
        printf("%lld %lld",sum1,x);return 0;}
    printf("%lld %lld %lld",sum,sum1,x);
}

