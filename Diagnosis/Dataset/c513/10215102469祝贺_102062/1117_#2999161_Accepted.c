#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<limits.h>
#define inf 1005

long long f(long long a,long long b){
    if(a<b) return b-a;
    else return a-b;
}

int main(){

    long long x,y;scanf("%lld%lld",&x,&y);
    int n;scanf("%d",&n);

    long long d=(long long)(2e16),minx=(long long)(1e15+1),miny=(long long)(1e15+1);

    for(int i=0;i<n;i++){
        long long newx,newy;scanf("%lld%lld",&newx,&newy);
        long long newd = f(x,newx)>f(y,newy)?f(x,newx):f(y,newy);
        if(d>=newd){
            if(d>newd){minx=newx;miny=newy;}
            else if(minx>=newx){
                if(minx>newx){minx=newx;miny=newy;}
                else if(miny>newy){minx=newx;miny=newy;}
            }
            d=newd;
        }
    }

    printf("%lld\n%lld %lld\n",d,minx,miny);
    return 0;
}
