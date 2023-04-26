#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    int n;
    while(scanf("%d",&n)&&n!=0){
        double res=n*(log(n)/log(10));
        res-=(long long int)res;
        res=pow(10,res);
        res=(int)res;
        while(res>10)res/=10;
        printf("%d\n",(int)res);
    }
    return 0;
}

