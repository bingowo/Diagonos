#include<stdio.h>

int f(int a,int x){
    if(x<3)
        return a;
    else
        return f(a,x-1)+f(a,x-2);
}

int p(int a,int n,int m,int x){
    if(x<3)
        return a;
    else if(x==n)
        return 0;
    else
        return p(a,n,m,x-1)+f(a,x-1)-f(a,x-2);
}

int main(){
    int a,n,m,x;
    scanf("%d%d%d%d",&a,&n,&m,&x);
    printf("%d",p(a,n,m,x));
}
