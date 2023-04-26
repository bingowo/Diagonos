#include<stdio.h>
#include<stdlib.h>

int Fibo[121];

int F(int n){
    int fibn;
    if(Fibo[n]!= 0)
        fibn=Fibo[n];
    else if(n==0||n==1)
        fibn=n;
    else
        fibn=F(n-1)+F(n-2);
    Fibo[n]=fibn;
    return fibn;
}

int main(){
    int T;
    scanf("%d",&T);
    int n;
    for(int i=0;i<T;i++){
        scanf("%d",&n);
        printf("case #%d:\n%d\n",i,F(n));
    }
    return 0;
}