#include<stdio.h>

int main(){
    int k,n;
    scanf("%d %d",&k,&n);
    int t[n];
    t[0]=0;t[1]=1;
    for(int i=2;i<n;i++)t[i]=0;
    for(int i=2;i<n;i++){
        for(int j=i-1;j>=0&&j>=i-k;j--)t[i]+=t[j];
    }
    printf("%d",t[n-1]);
}