#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int main(){
    double a,b,sum;
    int n,i,j;
    scanf("%lf %lf %d",&a,&b,&n);
    long long int num=a+b;
    printf("%lld",num);
    printf(".");
    long long int k,t;
    k=1;
    for(i=0;i<n;i++){
        k*=10;
        sum=(a+b)-num;
        sum*=k;
        j=(int)sum;
        j=j%k;
        printf("%d",j);
    }
}