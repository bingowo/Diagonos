#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int a,int b){
    int temp;
    while(b>0){
        temp=a%b;
        a=b;
        b=temp;
    }
    return a;
}

int main(){
    int T;
    scanf("%d",&T);
    int res1,res2;
    scanf("%d/%d",&res1,&res2);
    for(int t=0;t<T-1;t++){
        int add1,add2;
        scanf("%d/%d",&add1,&add2);
        res1=res1*add2+res2*add1;
        res2*=add2;
        int temp=gcd(res1,res2);
        res1/=temp;
        res2/=temp;
    }
    printf("%d/%d",res1,res2);
    return 0;
}
