#include<stdio.h>
long long int xiaoming[121];
long long int ming(int x){
    if(x<=0) return 0;
    if(x==1)
        return 1;
    if(x==2)
        return 1;
    if(x>2){
        if(xiaoming[x]==0)
            xiaoming[x]=ming(x-1)+ming(x-2);
        return xiaoming[x];
    }
    
}
int main(){
    int x;scanf("%d",&x);
    xiaoming[0]=0;
    xiaoming[1]=1;
    xiaoming[2]=1;
    for(int i=0;i<x;i++){
        int m;scanf("%d",&m);
        printf("%lld\n",ming(m));
    }
}