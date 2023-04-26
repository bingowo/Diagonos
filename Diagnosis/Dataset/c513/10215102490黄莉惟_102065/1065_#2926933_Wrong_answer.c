#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int num(int a,int n,int m,int x){
    if(x==1||x==2) return a;
    
}
int main(){
    int a,n,m,x;
    scanf("%d %d %d %d",&a,&n,&m,&x);
    printf("%d",num(a,n,m,x));
}