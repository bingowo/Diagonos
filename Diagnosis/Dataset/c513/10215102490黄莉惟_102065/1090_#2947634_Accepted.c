#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
int main(){
    double n,t;
    int k;
    while(scanf("%lf",&n)!=EOF){
        if(n!=0){
            k=n*log10(n);
            t=pow(10,n*log10(n)-k);
            printf("%d\n",(int)t);
        }
    }
}