#include<stdio.h>

long stamina(long m,long n){
    long stam;
    long max=m>n? m:n;
    long min=n<m? n:m;
    long num=m/n;
    max-=num*n;
    num*=4*min;
    return num+stamina(max,min);
}

int main(){
    long x,y;
    scanf("%ld%ld",&x,&y);
    printf("%ld",stamina(x,y));
    return 0;
}

