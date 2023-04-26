#include<stdio.h>

long long pow(int n){//计算 a的n次方
    long long r;
    if (n==0) r=1;
    if (n==1) r=2;
    r=pow(n/2);
    r=r*r;
    if (n%2) r=r*2;
    return r;
}

int main(){
    int t,a=0,n;
    scanf("%d",&t);
    long long num[31];
    for(int i=0;i<31;i++)num[i]=0;
    num[0]=1;num[1]=2;num[2]=4;num[3]=8;num[4]=16;
    while(a<t){
        scanf("%d",&n);
        if(num[n]==0){
            for(int i=5;i<31;i++)num[i]=2*num[i-1];
        }
        printf("case #%d:\n%lld\n",a,num[n]);
        a++;
    }
    return 0;
}
