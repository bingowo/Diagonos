#include<stdio.h>
long long f(long long a){
    long long b=0LL,c;
    int i=0;
    while(a>0LL){
        c=a%10LL;
        for(int k=0;k<i;k++)c*=9LL;
        i++;
        b+=c;
        a/=10LL;
    }
    return b;
}
int main(){
    long long a,b,a1,a2=0LL,b1,b2=0LL,c;  //c=范围内不含9的个数
    scanf("%lld%lld",&a,&b);
    c=f(b)-f(a)+1LL;
    a1=f(a-a%10LL)/9LL;
    b1=f(b-b%10LL)/9LL;
    for(long long int i=a-a%10LL;i<=a;i++){
        if(i%9LL==0LL)a2++;
    }
    for(long long int i=b-b%10LL;i<=b;i++){
        if(i%9LL==0LL)b2++;
    }
    a1=a1+a2;
    b1=b1+b2;
    c=c-(b1-a1);
    printf("%lld",c);
    return 0;
}
