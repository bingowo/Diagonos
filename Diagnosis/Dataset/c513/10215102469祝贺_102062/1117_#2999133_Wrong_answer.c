#include<stdio.h>
long long f(long long a,long long b){
    if(a<b) return b-a;
    else return a-b;
}
int main(){
    
    long long x,y;scanf("%lld%lld",&x,&y);
    int n;scanf("%d",&n);
    
    long long d=0,minx=x,miny=y;
    
    for(int i=0;i<n;i++){
        long long newx,newy;scanf("%lld%lld",&newx,&newy);
        long long newd = f(x,newx)<f(y,newy)?f(x,newx):f(y,newy);
        if(d>=newd){
            d=newd;
            if(minx>=newx){
                if(minx>newx){minx=newx;miny=newy;}
                else if(miny>newy){minx=newx;miny=newy;}
            }
        }
    }
    
    printf("%lld\n%lld %lld\n",d,minx,miny);
    return 0;
}