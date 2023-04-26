#include<stdio.h>
#include<string.h>
typedef struct{
    int cnt,v[200];
}BigInt;
BigInt Int2Big(long long int a){
    BigInt r={0,{0}};
    do{
        r.v[r.cnt++]=a%10LL;
        a/=10LL;
    }while(a>0LL);
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
BigInt Pow(int n,BigInt r){
    if(n==0)return Int2Big(1);
    if(n==1)return r;
    BigInt x=Pow(n/2,r),y={0,{0}};
    y=mul(x,x);
    if(n%2)y=mul(r,y);
    return y;
}
int mod(BigInt a,int b){
    int k=0;
    for(int i=a.cnt-1;i>=0;i--){
        k=a.v[i]%b;
        a.v[i-1]+=10*k;
    }
    return k;
}
int find_nine(BigInt a){
    for(int i=a.cnt-1;i>=0;i--)if(a.v[i]==9)return i;
    return -1;
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
int main(){
    long long int a1,b1,num=0LL;
    scanf("%lld%lld",&a1,&b1);
    BigInt a,b,one=Int2Big(1LL);
    a=Int2Big(a1);
    b=Int2Big(b1);
    while(compare(a,b)<=0){
        int p=find_nine(a);
        if(p==-1&&mod(a,9)!=0)num++;
        else if(p!=-1){
            a=add(a,Pow(p,Int2Big(10LL)));
            for(int s=p;s>=0;s--)a.v[s]=0;
            continue;
        }
        a=add(a,one);
    }
    printf("%lld",num);




}