#include<stdio.h>
typedef struct{
    int cnt,v[100];
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
        int carry=0;
        for(j=0;j<r.cnt;j++){
            int t=carry+q.v[i]*r.v[j]+key.v[i+j];
            key.v[i+j]=t%10;
            carry=t/10;
        }
        k=i+j+1;
        while(carry>0){
            int t=carry+key.v[k];
            key.v[k++]=t%10;
            carry=t/10;
    }
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
        int a,n,k;
        scanf("%d%d",&a,&n);
        BigInt x=Int2Big(a),y;
        y=Pow(n,x);
        k=y.cnt-1;
        printf("case #%d:\n",i);
        for(;k>0;k--)printf("%d",y.v[k]);
        printf("%d\n",y.v[0]);
    }
    return 0;
}