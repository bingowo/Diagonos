#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int feb(int n){
    if(n==1)return 1;
    if(n==2)return 2;
    return feb(n-1)+feb(n-2);
}

int f(int a,int t,int x){
    if(x==1)return a;
    if(x==2)return t;
    return f(a,t,x-1)+f(a,t,x-2);
}

int main(){
    int a,n,m,x,t=0;
    scanf("%d %d %d %d",&a,&n,&m,&x);
    if(n>=6)t=(m-a-feb(n-5)*a)/(1+feb(n-4));
    else if(n==5)t=m/2-a;
    else if(n==4)t=m/2-a/2;
    else if(n==3)t=m-2*a;
    int num=f(a,t,x-2)+a+t;
    printf("%d\n",num);
}
