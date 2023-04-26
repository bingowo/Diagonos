#include<stdio.h>
#include<math.h>

int num(long long a){
    a/=4;
    int b=sqrt(a);
    double c=sqrt(a);
    if(c>b)b++;
    return b;
}

int main(){
    long long n;
    scanf("%lld",&n);
    int m=num(n);
    printf("d",m);
}