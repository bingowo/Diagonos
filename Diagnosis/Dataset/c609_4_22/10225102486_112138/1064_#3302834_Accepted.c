#include<stdio.h>

long long stamina(long long m,long long n){
    long long max=m>n? m:n;
    long long min=n<m? n:m;
    if(min==0)
        return 0;
    long long num=m/n;
    max-=num*min;
    num*=4*min;
    return num+stamina(max,min);
}

int main(){
    long long x,y;
    scanf("%lld%lld",&x,&y);
    printf("%lld",stamina(x,y));
    return 0;
}

