#include <stdio.h>
#include <math.h>

long long res(long long x,long long y){
    long long min,max,all,num,temp;
    min=(x>y)?y:x;
    max=(x<y)?y:x;
    all=0;
    while(max%min){
        num=max/min;
        all+=min*4*num;
        temp=min;
        min=max%min;
        max=temp;
    }
    all+=max*4;
    return all;
}

int main(){
    long long x,y,ans;
    scanf("%lld %lld",&x,&y);
    ans=res(x,y);
    printf("%lld\n",ans);
    return 0;
}