#include<stdio.h>
#include<stdlib.h>
int main(){
    int k,n;
    scanf("%d%d",&k,&n);
    int *num=(int*)malloc(sizeof(int)*n);
    num[0]=0;num[1]=1;
    for(int i=2;i<k;i++){
        int t=0;
        for(int j=0;j<i;j++){
            t+=num[j];
        }
        num[i]=t;
    }
    for(int i=k;i<n;i++){
        int t=0;
        for(int j=i-k;j<i;j++){
            t+=num[j];
        }
        num[i]=t;
    }
    printf("%d\n",num[n-1]);
    free(num);
}