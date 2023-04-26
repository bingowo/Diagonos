#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    int n;
    int a[21]={0};//以0结尾的不含101子串的
    int b[21]={0};//以1结尾的不含101子串的
    a[1]=b[1]=1;
    for(int i=2;i<21;i++){
        a[i]=a[i-1]+b[i-1];
        b[i]=b[i-1]+a[i-1]-b[i-2];
    }
    while(scanf("%d",&n)==1&&n!=-1){
        printf("%d\n",a[n]+b[n]);
    }
}