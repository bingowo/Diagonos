#include <stdio.h>
#include <stdlib.h>

long long int tl(long long int a,long long int b,long long int sum,long long int s,long long int alls){
    if(s==alls)return 4*sum;
    else{
    if(a<b){
        sum=sum+a;
        s=a*a+s;
        return tl(b-a,a,sum,s,alls);
    }
    else{
        sum=sum+b;
        s=b*b+s;
        return tl(b,a-b,sum,s,alls);
    }}
}

int main(){
    long long int x,y;
    scanf("%lld%lld",&x,&y);
    if(x%y==0)printf("%lld",4*a);
    else printf("%lld",tl(x,y,0,0,x*y));
    return 0;
}
