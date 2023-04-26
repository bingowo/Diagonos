#include<stdio.h>
long long int ming(int x){
    if(x<=0) return 0;
    if(x==1) return 1;
    if(x==2) return 2;
    if(x==3) return 4;
    if(x==4) return 8;
    if(x>4) return ming(x-1)+ming(x-2)+ming(x-3)+ming(x-4);
}
int main(){
    int x;
    scanf("%d",&x);
    for(int i=0;i<x;i++){
        int t;
        scanf("%d",&t);
        long long int m=ming(t);
        printf("%lld\n",m);
    }
}