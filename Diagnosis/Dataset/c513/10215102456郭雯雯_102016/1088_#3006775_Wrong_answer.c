#include<stdio.h>

long long num[41][21];

long long c(int m,int n){
    int k=m/2;
    if(n>k)n=m-n;
    if(num[m][n]!=0)return num[m][n];
    if(n==0){num[m][n]=1;return 1;}
    else if(n==1){num[m][n]=m;return (long long)m;}
    else {num[m][n]=c(m-1,n)+c(m-1,n+1);return c(m-1,n)+c(m-1,n+1);}
}

int main(){
    int t,a=0;
    scanf("%d",&t);
    for(int i=0;i<41;i++)
        for(int j=0;j<21;j++)num[i][j]=0;
    while(a<t){
        int m,n;
        scanf("%d %d",&m,&n);
        long long ans=c(m,n);
        printf("case #%d:\n%lld\n",a,ans);
        a++;
    }
}