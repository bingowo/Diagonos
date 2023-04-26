#include <stdio.h>
int cnt=0;
long long int Fanshu(long long int n){
    long long int m=0;
    long long int n0=n;
    while(n>9){
        m=10*m+n%10;
        n/=10;
    }
    m=10*m+n;
    if(m!=n0){cnt++;return Fanshu(m+n0);}
    else if(m==n0){return m;}
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%d %lld",cnt,Fanshu(n));
    return 0;
}