#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int ui(int n){
    if(n==1) return 1;
    if(n==2) return 0;
    return ui(n-1)+ui(n-2);
}
int vi(int n){
    if(n==1) return 0;
    if(n==2) return 1;
    return vi(n-1)+vi(n-2);
}
int sui(int n){
    if(n==1) return 1;
    if(n==2) return 1;
    return sui(n-1)+vi(n-1)-vi(n-2);
}
int svi(int n){
    if(n==1) return 0;
    if(n==2) return 0;
    return svi(n-1)+vi(n)-vi(n-1);
}
int main(){
    int sum;
    int a,n,m,x;
    scanf("%d %d %d %d",&a,&n,&m,&x);
    int t=(m-sui(n-1)*a)/svi(n-1);
    sum=sui(x)*a+svi(x)*t;
    printf("%d",sum);
}