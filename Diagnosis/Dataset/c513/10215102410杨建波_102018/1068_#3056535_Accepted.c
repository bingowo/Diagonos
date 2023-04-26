#include<stdio.h>
#include<math.h>

int f(int m,int n){
    if(m == n)return 1;
    if(m > n)return 0;
    return 2*f(m, n-1)+pow(2,n-m-1)-f(m,n-m-1);
}

int main(){
    int n,m;
    while(1){
        scanf("%d %d",&n,&m);
        if(m == -1&&n == -1)break;
        printf("%d\n",f(m,n));
    }
    
}