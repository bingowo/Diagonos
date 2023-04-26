#include<stdio.h>
#include<stdlib.h>
long long ans=0;
void plough(long long a,long long b){
    if(a%b==0){
       ans+=4*a;
       return;
    }
    if(b%a==0){
       ans+=4*b;
       return;
    }
    if(a==b){
        ans+=4*a;
        return ;
    }
    else if(a>b){
        ans+=4*b;
        plough(a-b,b);
    }
    else if(a<b){
        ans+=4*a;
        plough(a,b-a);
    }
}
int main(){
    long long x,y;
    scanf("%lld %lld",&x,&y);
    plough(x,y);
    printf("%lld",ans);
    return 0;
}