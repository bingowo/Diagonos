#include<stdio.h>
#include<string.h>
typedef unsigned long long ull;
ull getnum(ull x){
    ull res=0;
    do{
        res=res*10+x%10;
        x/=10;
    }while(x);
    return res;
}
int main(){
    ull x;
    scanf("%llu",&x);
    int cnt=0;
    while(x!=getnum(x)){
        x+=getnum(x);
        cnt++;
    }
    printf("%d %llu",cnt,x);
}