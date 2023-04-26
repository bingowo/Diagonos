#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long int f(int n,int m){
    if(n<m)return 0;
    if(n==m)return 1;
    return 2*f(n-1,m)-f(n-m-1,m)+pow(2,n-m-1);
}

int main(){
    int m,n;
    while(scanf("%d %d",&n,&m)&&(m!=-1||n!=-1)){
        printf("%lld\n",f(n,m));
    }
    return 0;
}

