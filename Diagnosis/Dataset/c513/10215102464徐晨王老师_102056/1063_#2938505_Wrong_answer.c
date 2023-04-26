#include <stdio.h>
#include <stdlib.h>

long long int tl(long long int a,long long int b,long long int sum,long long int s,long long int alls){
    if(s==alls)return 4*sum;
    if(a%b==0)return 4*b*(a/b);
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
    printf("%lld",tl(x,y,0,0,x*y));
    return 0;
}
