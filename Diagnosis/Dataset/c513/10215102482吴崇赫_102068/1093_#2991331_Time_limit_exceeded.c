#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 105

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
    long long n;
    scanf("%lld",&n);
    n++;
    while(!isMiao(n))n++;
    printf("%lld",n);
    return 0;
}