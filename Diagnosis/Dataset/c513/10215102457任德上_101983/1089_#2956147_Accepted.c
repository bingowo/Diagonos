#include<stdio.h>
#include<string.h>
typedef struct{
    int cnt,v[10000];
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
int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int a,b,n;
        scanf("%d%d%d",&a,&b,&n);
        BigInt a1;
        a1=Int2Big(a);
        a1=Pow(b,a1);
        printf("case #%d:\n",i);
        for(int k=n-1;k>=0;k--)printf("%d",a1.v[k]);
        printf("\n");
    }
    return 0;
}