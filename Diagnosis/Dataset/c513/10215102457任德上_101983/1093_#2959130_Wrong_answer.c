#include<stdio.h>
#include<string.h>
typedef struct{
    int cnt,v[200];
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
BigInt transform(char *s){
    BigInt a;
    a.cnt=strlen(s);
    for(int i=a.cnt-1;i>=0;i--){a.v[i]=*s-'0';s++;}
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
int main(){
    char s[1000];
    scanf("%s",s);
    BigInt a,b,c,one=Int2Big(1);
    a=transform(s);
    a=add(a,one);
    while(1){
        int p=find_nine(a);
        if(p==-1&&mod(a,9)!=0)break;
        else if(p!=-1)a=add(a,Pow(p,Int2Big(10)));
        else a=add(a,one);
    }
    for(int i=a.cnt-1;i>=0;i--)printf("%d",a.v[i]);
    return 0;
}
