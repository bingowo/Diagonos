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
int compare(BigInt a,BigInt b){
    if(a.cnt>b.cnt)return 1;
    else if(a.cnt<b.cnt)return -1;
    else{
        for(int i=a.cnt-1;i>=0;i--){
            if(a.v[i]>b.v[i])return 1;
            else if(a.v[i]<b.v[i])return -1;
        }
        return 0;
    }
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
BigInt sub(BigInt a,BigInt b){
    int i=0;
    while(i<a.cnt||i<b.cnt){
        a.v[i]=a.v[i]>=b.v[i]?a.v[i]-b.v[i]:a.v[i]-b.v[i]+10*(a.v[i+1]-(--a.v[i+1]));
        i++;
    }
    while(a.v[a.cnt-1]==0&&a.cnt>1)a.cnt--;
    return a;
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
BigInt div(BigInt a,BigInt b){
    BigInt c={0,{0}},zero=Int2Big(0),d;
    int sum=0,i;
    if(compare(a,b)==-1)return Int2Big(0);
    if(compare(a,b)==0)return Int2Big(1);
    if(compare(a,mul(b,Pow(a.cnt-b.cnt,Int2Big(10))))>0)i=a.cnt-b.cnt;
    else i=a.cnt-b.cnt-1>=0?a.cnt-b.cnt-1:0;
    for(;i>=0;i--){
        d=mul(b,Pow(i,Int2Big(10)));
        while(compare(a,d)>=0){a=sub(a,d);sum++;}
        c=add(c,mul(Int2Big(sum),Pow(i,Int2Big(10))));
        sum=0;
        if(compare(zero,a)==0)break;
    }
    return c;
}
BigInt Mod(BigInt a,BigInt b){
    BigInt c=sub(a,mul(div(a,b),b));
    return c;
}

int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int a,b;
        BigInt a1,b1,c=Int2Big(0),prime=Int2Big(0),now=Int2Big(0);
        scanf("%d%d",&a,&b);
        a1=Int2Big(a),b1=Int2Big(b);
        do{
            a1=mul(a1,Int2Big(100));
            c =div(a1,b1);
            now=Mod(a1,b1);
            if(compare(now,prime)==0)break;
            prime=now;
        }while(1);
        printf("0.");
        int start=0,end=0;
        for(int k=c.cnt-1;k>0;k--)printf("%d",c.v[k]);
        printf("\n");


    }







}