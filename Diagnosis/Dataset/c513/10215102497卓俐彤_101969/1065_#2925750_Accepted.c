#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int feb(int n){
    if(n==1)return 1;
    if(n==2)return 2;
    return feb(n-1)+feb(n-2);
}

int f(int n){
    int res=0;
    while(n!=0)res+=feb(n--);
    return res;
}

int main(){
    int a,n,m,x,t=0;
    scanf("%d %d %d %d",&a,&n,&m,&x);
    if(n>6)t=(m-(3+f(n-6))*a)/(f(n-5)+1);
    else if(n==6)t=(m-3*a)/2;
    else if(n==5)t=m-2*a;
    int num;
    if(x==1||x==2)num=a;
    else if(x==n-1)num=m;
    else if(x==3)num=2*a;
    else if(x==4)num=2*a+t;
    else if(x==5)num=3*a+2*t;
    else num=(3+f(x-5))*a+(1+f(x-4))*t;
    printf("%d\n",num);
}
