#include<stdio.h>

int f(int a,int x){
    if(x<3)
        return a;
    else
        return f(a,x-1)+f(a,x-2);
}

int g(int a,int x){
    if(n==1)
        return 0;
    else
        return f(a,x-1);
}

int p(int a,int n,int m,int x){
    if(x<3)
        return a;
    else if(x==n)
        return 0;
    else
        return p(a,n,m,x-1)+f(a,x-1)-g(a,x-1);
}

int main(){
    int a,n,m,x;
    scanf("%d%d%d%d",&a,&n,&m,&x);
    printf("%d",p(a,n,m,x));
}
// 上车f 下车g 第h站有h(n)人 初始a人 n站 最后一站m人
//f(n)=f(n-1)+f(n-2),g(n)=f(n-1),h(n)=h(n-1)+f(n-1)-g(n-1)
//
