#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int find(long long int b){
    char buffer[20];
    sprintf(buffer,"%lld",b);
    int len=strlen(buffer);
    for(int i=len;i>0;i--){
        if(buffer[len-i]=='9')return i-1;
    }
    return -1;
}
int len(long long int a){
    if(a==0LL)return 1;
    int len=0;
    while(a>0){
        len++;
        a/=10LL;
    }
    return len;
}
long long int PowLL(long long int m,int k){
    if(k==0)return 1LL;
    if(k==1)return m;
    long long int a=PowLL(m,k/2);
    a=a*a;
    if(k%2)a=m*a;
    return a;
}
int main(){
    long long int a,b,num=0LL,i;
    int k;
    scanf("%lld%lld",&a,&b);
    i=a;
    while(i<=b){
        k=find(i);
        if(i%9LL!=0LL&&k==-1)num++;
        else if(k!=-1){
            long long int p=PowLL(10LL,k);
            i+=PowLL(10LL,k);
            i=i/p;
            continue;
        }
        i++;
    }
    printf("%lld",num);
    return 0;
}