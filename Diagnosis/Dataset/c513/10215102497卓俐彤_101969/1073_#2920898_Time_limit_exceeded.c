#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



int main(){
    long long int a,b,num;
    num=0;
    scanf("%lld %lld",&a,&b);
    for(long long int i=a;i<=b;i++){
        int d=1,flag=1;
        long long int n=i;
        while(n!=0){
            if(n%10==9){
                flag=0;
                i=i+d-1;
                break;
            }
            d*=10;
            n/=10;
        }
        if(i%9==0)flag=0;
        num+=flag;
    }
    printf("%lld\n",num);
    return 0;
}
