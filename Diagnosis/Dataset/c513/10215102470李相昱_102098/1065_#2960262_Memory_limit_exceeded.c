#include <stdio.h>
int fib(int n){
    if(n==0){
        return 0;
    }
    if(n==1||n==2){
        return 1;
    }
    return fib(n-1)+ fib(n-2);
}
int main() {
    int a,n,m,x;
    scanf("%d%d%d%d",&a,&n,&m,&x);
    int a1 =0,p1=0,p;
    for(int i=0;i<n-4;i++){
        a1 = a1+ fib(i);
    }
    p1 = a1+ fib(n-4);
    a1 = a1+2;
    p = (m-a1*a)/p1;
    int sum =0;
    int a2=0,p2=0;
    for(int j=0;j<=x-4;j++){
        a2 = a2+ fib(j);
    }
    p2 = a2+ fib(x-3);
    a2 = a2+2;
    sum = a2*a+p2*p;
    printf("%d",sum);
    return 0;
}
