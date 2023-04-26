#include<stdio.h>
#include<stdlib.h>

int main (){
    long long x,y;
    scanf("%lld%lld",&x,&y);
    long long area = 0;
    long long a,b;
    while (y){
        a = x/y;
        b = x%y;
        area += 4*a*y;
        x = y;
        y = b;
    }
    printf("%lld",area);

}