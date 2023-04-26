#include<stdio.h>
#include<math.h>

int f(int n){
    if(n == 3)return 7;
    if(n == 1)return 2;
    if(n == 2)return 4;
    if(n == 0)return 0;
    return f(n-1)*2 - f(n-2) + f(n-3);
}

int main(){
    int n;
    while(scanf("%d",&n)&&n != -1){
        printf("%d\n",f(n));
    }
}