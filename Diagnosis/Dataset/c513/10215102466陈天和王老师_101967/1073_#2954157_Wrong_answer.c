#include <stdio.h>
int isbumiao(long long int i){
    if(i%9==0) return 1;
    else{
        while(i!=0){
            if(i%10==9) return 1;
            else i/=10;
        }
        return 0;
    }
}
int main(){
    long long a,b;
    scanf("%lld%lld\n",&a,&b);
    long long i;
    long long cnt=2;
    for(i=a+1;i<b;i++){
        if(isbumiao(i)) continue;
        else cnt++;
    }
    printf("%lld",cnt);
}