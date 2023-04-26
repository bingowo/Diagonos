#include<stdio.h>
#include<string.h>
long long int count(int n){
    long long int s[100];
    s[1]=2;
    s[2]=4;
    s[3]=7;
    for(int i=4;i<=n;i++){
        s[i]=2*s[i-1]-s[i-2]+s[i-3];
    }
    return s[n];
}
int main(){
    int n;
    long long int num;
    scanf("%d",&n);
    while(n!=-1){
        num=count(n);
        printf("%lld",num);
        scanf("%d",&n);
    }
}