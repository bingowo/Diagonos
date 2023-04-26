#include<stdio.h>
#include<string.h>
typedef struct{
    int cnt,v[1005];
}BigInt;
BigInt Int2Big(int a){
    BigInt r={0,{0}};
    do{
        r.v[r.cnt++]=a%10;
        a/=10;
    }while(a>0);
    return r;
}
BigInt mul(BigInt q,BigInt r){
    BigInt key={q.cnt+r.cnt,{0}};
    int i,k,j;
    for(i=0;i<q.cnt;i++){
        for(j=0;j<r.cnt;j++){
            key.v[i+j]=q.v[i]*r.v[j]+
        }
    }
    for(i=0;i<q.cnt+r.cnt-1;i++){
        key.v[i+1]+=key.v[i]/10;
        key.v[i]%=10;
    }
    if(key.v[key.cnt-1]==0)key.cnt--;
    return key;
}
BigInt add(BigInt a,BigInt b){
    int i=0;
    while(i<a.cnt||i<b.cnt){
        a.v[i]+=b.v[i];
        a.v[i+1]+=a.v[i]/10;
        a.v[i]%=10;
        i++;
    }
    a.cnt=i+1;
    while(a.v[a.cnt-1]==0)a.cnt--;
    return a;
}
int prime_number(int a){
    if(a==1)return 0;
    if(a==2)return 1;
    if(a%2==0)return 0;
    for(int i=3;i<a;i=i+2){
        if(a%i==0)return 0;
    }
    return 1;
}
int main(){
    int prime[26],n[26]={0},i=0;
    char c;
    for(int i=1,j=1;j<26;i++){
        if(prime_number(i))prime[j++]=i;
    }
    prime[0]=1;
    while(scanf("%d%c",&n[i++],&c)){
        if(c!=',')break;
    }
    if(n[0]==0&&i==1){printf("0");return 0;}
    BigInt key={0,{0}};
    for(int k=i-1;k>=0;k--){
        BigInt a,b;
        a=Int2Big(n[i-k-1]);
        b=Int2Big(prime[k+1]);
        key=add(mul(key,b),a);
    }
    for(int i=key.cnt-1;i>=0;i--)printf("%d",key.v[i]);
    return 0;
}