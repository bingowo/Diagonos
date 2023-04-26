#include<stdio.h>

int main(){
    int t;
    scanf("%d",&t);
    int f[21],g[21];
    f[0]=g[0]=0;
    f[1]=g[1]=1;
    for(int i=2;i<=20;i++){
        f[i]=f[i-1]+g[i-1];
        g[i]=f[i]-g[i-2];
    }
    for(int i=0;i<t;i++){
        
        int x;
        scanf("%d",&x);
        printf("%d",f[x]+g[x]);
    }
}