#include<stdio.h>
int ming(int x){
    if(x<=0) return 0;
    if(x>0){
        return ming(x-1)+ming(x-2);
    }
}
int main(){
    int x;scanf("%d",&x);
    for(int i=0;i<x;i++){
        int m;scanf("%d",&m);
        printf("%d",ming(m));
    }
}