#include<stdio.h>
#include<stdlib.h>
long long ans=0;
long long plough(long long a,long long b){
    if(a==b){
        ans+=4*a;
        return ans;
    }
    else if(a>b){
        ans+=4*b;
        plough(a-b,b);
    }
    else if(a<b){
        ans+=a*4;
        plough(a,b-a);
    }
}
int main(){
    long long x,y;
    scanf("%lld %lld",&x ,&y);
    plough(x,y);
    printf("%lld",ans);
    return 0;
}