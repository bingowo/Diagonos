#include<stdio.h>
long long int find(long long int b){
    long long int  a,flag=1LL;
    do{
        a=b%10LL;
        if(a==9LL){flag=0LL;break;}
        b/=10LL;
    }while(b!=0LL);
    return flag;
}
int main(){
    long long int a,b,num=0LL;
    scanf("%lld%lld",&a,&b);
    for(long long int i=a;i<=b;i++){
        if(i%9LL!=0LL&&find(i)==1LL)num++;
    }
    printf("%lld",num);
    return 0;
}