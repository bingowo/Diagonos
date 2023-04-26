#include<stdio.h>
#include <stdlib.h>
#include<string.h>
int f(int n,int m){
    if(n<m) return 0;
    if(n==m) return 1;
    return 2*f(n-1,m)-f(n-m-1,m)+(1<<(n-m-1));
}
int main(){
    int m,n;
    while(scanf("%d",&n)!=-1||scanf("%d",&m)!=-1){
        printf("%d\n",f(n,m));
    }
    
}