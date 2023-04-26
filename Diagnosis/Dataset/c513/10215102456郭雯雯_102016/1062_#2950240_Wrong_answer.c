#include<stdio.h>

long long f(int n){
    long long t;
    if(n==1)return 1;
    if(n==2)return 2;
    if(n==3)return 4;
    if(n==4)return 8;
    if(n>4)return f(n-1)+f(n-2)+f(n-3)+f(n-4);
}
int main(){
    int t,n,a=0;
    scanf("%d",&t);
    long long num[55];
    for(int i=0;i<55;i++)num[i]=0;
    num[0]=0;num[1]=1;num[2]=2;num[3]=4;num[4]=8;
    while(a<t){
        scanf("%d",&n);
        if(n<5)printf("case #%d:\n%lld\n",a,num[n]);
        else{
            for(int i=n-1;i>(n-5);i--)num[n]+=num[i];
            printf("case #%d:\n%lld\n",a,num[n]);
        }
        a++;
    }
    return 0;
}