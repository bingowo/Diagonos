#include <stdio.h>
long long int Sum(long long int x,long long int y){
    if(x==y){
        return 4*y;
    }if(x%y==0){
        return (x/y)*4*y;
    }
    return (x/y)*4*y+ Sum(y,x%y);
}
int main() {
    long long int x,y;
    scanf("%lld%lld",&x,&y);
    printf("%lld", Sum(x,y));
    return 0;
}
