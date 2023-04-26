#include<stdio.h>
#include<math.h>

int num(long long a){
    double m=a/4;
    int b=(int)sqrt(m);
    double c=sqrt(m);
    if(c-b>0)b++;
    return b;
}

int main(){
    long long n;
    scanf("%lld",&n);
    int m=num(n);
    printf("%d",m);
}