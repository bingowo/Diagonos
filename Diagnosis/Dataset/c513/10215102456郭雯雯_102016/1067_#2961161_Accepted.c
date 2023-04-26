#include<stdio.h>

int main(){
    int t,n,a=0;
    scanf("%d",&t);
    long long num[74];
    for(int i=0;i<74;i++)num[i]=0;
    num[0]=0;num[1]=1;num[2]=1;
    for(int j=3;j<=73;j++){
        for(int i=j-1;i>(j-4);i--)num[j]+=num[i];
    }
    while(a<t){
        scanf("%d",&n);
        printf("case #%d:\n%lld\n",a,num[n]);
        a++;
    }
    return 0;
}

