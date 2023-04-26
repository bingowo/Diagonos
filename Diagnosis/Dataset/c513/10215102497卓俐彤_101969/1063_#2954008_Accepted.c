#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long int energy(long long int a,long long int b){
    long long int min=a<b?a:b;
    long long int max=a>b?a:b;
    if(min==max)return 4*min;
    else if(max%min==0)return 4*min*(max/min);
    else return energy(min,min)+energy(max-min,min);
}

int main(){
    long long int a,b;
    scanf("%lld %lld",&a,&b);
    printf("%lld\n",energy(a,b));
}
