#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef long long ll;
typedef unsigned long long ull;

int a,b,c,d;

int num1(int w){
    int r=0;
    while(w--)
        r=r*3+1;
    return r;
}

bool PrintA(int x){
    if(x==0) return 0;

    if(!PrintA(x/3) && (x+2)%3==0) return 0;//不输出前置0
    printf("%d",(x+2)%3);
    return 1;
}

void PrintB(int x){
    if(d==0) return;
    d--;
    PrintB(x/3);
    printf("%d",(x+2)%3);
}

int main(){
    scanf("%d%d",&b,&c);
    d=log(c)/log(3)+1;
    a=b/c;
    b%=c;
    a+=num1(log(a)/log(3)+2);
    b+=num1(log(b)/log(3)+2);
    a+=b/c;
    b%=c;
    if(!PrintA(a))
        printf("0");
    if(c>1){
        printf(".");
        PrintB(b);
    }
    printf("\n");

    return 0;
}
