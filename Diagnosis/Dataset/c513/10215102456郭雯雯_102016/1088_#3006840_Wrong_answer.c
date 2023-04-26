#include<stdio.h>

long long num[41][21];

long long c(int m,int n){
    int k=m/2;
    if(n>k)n=m-n;
    if(num[m][n]!=0)return num[m][n];
    else {num[m][n]=c(m-1,n)+c(m-1,n+1);return num[m][n];}
}

int main(){
    int t,a=0;
    scanf("%d",&t);
    for(int i=1;i<41;i++)
        for(int j=0;j<21;j++){
            if(j==0)num[i][j]=1;
            else if(j==1)num[i][j]=i;
            else if(j==2)num[i][j]=i*(i-1)/2;
            else num[i][j]=0;
        }
    while(a<t){
        int m,n;
        scanf("%d %d",&m,&n);
        long long ans=c(m,n);
        printf("case #%d:\n%lld\n",a,ans);
        a++;
    }
}