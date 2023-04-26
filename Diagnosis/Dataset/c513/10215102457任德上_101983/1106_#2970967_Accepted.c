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
BigInt Pow(int n,BigInt r){       //计算r的n次方
    if(n==0)return Int2Big(1);
    if(n==1)return r;
    BigInt x=Pow(n/2,r),y={0,{0}};
    y=mul(x,x);
    if(n%2)y=mul(r,y);
    return y;
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
int main(){
    char s[1001],*s1;
    scanf("%s",s);
    s1=s;
    int t=strlen(s);
    if(t==1)printf("1");
    else if(t==2){
        if(*s1==*(s1+1))printf("1");
        else printf("4");
    }
    else{
        BigInt x,y,z,q=Int2Big(1000000007),p;
        x=Int2Big(3);
        y=Int2Big(2);
        z=Int2Big(1);
        if(*s1!=*(s1+1))z=mul(z,y);
        s1++;
        while(*(s1+1)!=0){
            if(*(s1+1)!=*s1&&*s1!=*(s1-1)&&*(s1-1)!=*(s1+1))z=mul(z,x);
            else if(*s1!=*(s1+1)||*s1!=*(s1-1)||*(s1+1)!=*(s1-1))z=mul(z,y);
            s1++;
        }
        if(*s1!=*(s1-1))z=mul(z,y);
        p=div(z,q);
        z=sub(z,mul(p,q));
        for(int i=z.cnt-1;i>=0;i--)printf("%d",z.v[i]);
    }
    return 0;
}