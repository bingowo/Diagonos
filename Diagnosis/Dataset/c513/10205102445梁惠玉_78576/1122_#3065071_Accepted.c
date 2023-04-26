#include<stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
    long long n,digit[20];
    int l=0;
    scanf("%lld",&n);
    if(n==0L)
    {
        printf("0");
    }
    while(n)
    {
        digit[l++]=n%2333L;
        n/=2333L;
    }
    while(l)
    {
        printf("%lld ",digit[--l]);
    }
    printf("\n");
    }
    return 0;
}