#include<stdio.h>
#include<string.h>
typedef struct{
    int cnt,v[2000];
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
            key.v[i+j]=q.v[i]*r.v[j]+key.v[i+j];
        }
    }
    for(i=0;i<q.cnt+r.cnt-1;i++){
        key.v[i+1]+=key.v[i]/10;
        key.v[i]%=10;
    }
    if(key.v[key.cnt-1]==0)key.cnt--;
    return key;
}
BigInt Pow(int n,BigInt r){
    if(n==0)return Int2Big(1);
    if(n==1)return r;
    BigInt x=Pow(n/2,r),y={0,{0}};
    y=mul(x,x);
    if(n%2)y=mul(r,y);
    return y;
}
BigInt transform(int n){
    BigInt a;
    int c;
    a=Int2Big(n);
    c=a.v[a.cnt-1];
    return Int2Big(c);
}
int main(){
    int t;
    while(scanf("%d",&t)){
        if(t==0)break;
        BigInt a1,*a;
        a1=transform(t);
        a1=Pow(t,a1);
        printf("%d\n",a1.v[a1.cnt-1]);
    }
    return 0;
}
