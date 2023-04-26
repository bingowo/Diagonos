#include<stdio.h>
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
int main(){
    BigInt num[200]={Int2Big(0)};
    int k,m;
    scanf("%d%d",&k,&m);
    num[12]=Int2Big(1);
    m=m+10;
    for(int i=13;i<=m;i++){
        for(int p=i-k;p<i;p++){
            num[i]=add(num[p],num[i]);
        }
    }
    for(int i=num[m].cnt-1;i>=0;i--)printf("%d",num[m].v[i]);
    return 0;
}