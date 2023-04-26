#include<stdio.h>
#include<string.h>
#define N 20

int isMiao(long long n)
{
    if(n%9==0)return 0;
    char s[N];for(int i=0;i<N;++i)s[i]=0;
    int p=0; s[p]='0';
    while(n){
        s[p]=n%10+'0';
        if(s[p]=='9')return 0;
        n/=10;++p;
    }
    return 1;
}

int main()
{
    long long a,b,cnt=0;
    scanf("%lld%lld",&a,&b);
    for(long long i=a;i<=b;++i){
        if(isMiao(i))cnt++;
    }
    printf("%lld",cnt);
    return 0;
}
