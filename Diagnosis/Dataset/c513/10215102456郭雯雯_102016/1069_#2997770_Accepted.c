#include<stdio.h>

long long chag(long long z){
    long long m=0;
    while(z>0){
        int a=z%10;
        m*=10;
        m+=a;
        z/=10;
    }
    return m;
}

int hw(long long s){
    long long s1=chag(s);
    if(s==s1)return 1;
    return 0;
}

int main(){
    long long n,m=0,s,z;
    int num=0;
    scanf("%lld",&n);
    m=chag(n);
    s=n+m;
    num++;
    while(hw(s)==0){
        n=s;
        m=chag(n);
        s=n+m;
        num++;
    }
    printf("%d %lld",num,s);
}