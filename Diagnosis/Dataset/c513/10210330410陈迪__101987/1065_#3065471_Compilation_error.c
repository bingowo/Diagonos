#include<stdio.h>

int upbusA(int n){
    if(n==1){
        return 1;
    }else if(n==2){
        return 0;
    }else{
        return upbusA(n-1) + upbusA(n-2);
    }
}

int upbusB(int n){
    if(n==1){
        return 0;
    }else if(n==2){
        return 1;
    }else{
        return upbusB(n-1) + upbusB(n-2);
    }
}

int downbusA(int n){
    if(n==1 || n==2){
        return 0;
    }else{
        return upbusA(n-1);
    }
}

int downbusB(int n){
    if(n==1){
        return 0;
    }else if(n==2){
        return 1;
    }else {
        return upbusB(n-1);
    }
}

int lastA(int n){
    if(n==1 || n==2){
        return 1;
    }else{
        return (upbusA(n) - downbusA(n)) + lastA(n-1);
    }
}

int lastB(int n){
    if(n==1 || n==2){
        return 0;
    }else{
        return     (upbusB(n) - downbusB(n)) + lastB(n-1);
    }
}

int main(){
    int b,a,n,m,x,num;
    scanf("%d %d %d %d",&a,&n,&m,&x);
        b = (m-(lastA(n-1) * a)) / lastB(n-1);
        num = (lastA(x)*a) + (lastB(x)*b);
        printf("%d",num);    
    
    
    return 0;
