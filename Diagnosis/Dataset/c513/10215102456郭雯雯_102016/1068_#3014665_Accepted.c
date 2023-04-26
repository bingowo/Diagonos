#include<stdio.h>

long long num[32];

int f(int n,int m){
    if(n<m)return 0;
    else if(n==m)return 1;
    else return 2*f(n-1,m)+num[n-m-1]-f(n-m-1,m);
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    num[0]=1;
    for(int i=1;i<32;i++)num[i]=(long long)num[i-1]*2;
    while(n!=-1&&m!=-1){
        int s=f(n,m);
        printf("%lld\n",s);
        scanf("%d %d",&n,&m);
    }
}