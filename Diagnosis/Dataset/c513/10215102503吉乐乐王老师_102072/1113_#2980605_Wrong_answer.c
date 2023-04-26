#include<stdio.h>
#include<stdlib.h>
typedef unsigned long long int ull;
int main(){
    int k,n;
    scanf("%d%d",&k,&n);
    ull *num=(ull*)malloc(sizeof(ull)*n);
    num[0]=0;num[1]=1;
    for(int i=2;i<k;i++){
        ull t=0;
        for(int j=0;j<i;j++){
            t+=num[j];
        }
        num[i]=t;
    }
    for(int i=k;i<n;i++){
        ull t=0;
        for(int j=i-k;j<i;j++){
            t+=num[j];
        }
        num[i]=t;
    }
    printf("%llu\n",num[n-1]);
    free(num);
}