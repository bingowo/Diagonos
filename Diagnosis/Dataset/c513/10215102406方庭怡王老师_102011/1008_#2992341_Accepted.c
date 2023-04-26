#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int f(int x,int y){
    int count=0;
    int n = x^y;
    while(n){
        if(n&1)count++;
        n>>=1;
    }
    return count;
}
int main(){
    int n=0,x=0,y=0;
    scanf("%d",&n);
    while(n-->0){
        scanf("%d %d",&x,&y);
        printf("%d\n",f(x,y));
    }
    return 0;
}