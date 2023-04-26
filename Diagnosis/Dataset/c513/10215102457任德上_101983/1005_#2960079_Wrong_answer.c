#include<stdio.h>
#include<string.h>
typedef struct{
    int cnt,v[300];
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
    if(compare(a,b)==-1||compare(a,zero)==0)return Int2Big(0);
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
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        char s[200];
        scanf("%s",s);
        BigInt a={0,{0}},ten=Int2Big(10),c,eight=Int2Big(8);
        int len=strlen(s);
        for(int k=len-1;k>=2;k--){
            c=Int2Big(*(s+k)-'0');    //获取现在位数的数字
            c=mul(c,Pow(3*(len-k-1),ten));
            a=add(c,a);
            a=mul(a,Pow(3,ten));
            a=div(a,eight);
        }
        printf("case #%d:\n",i);
        int item=0;
        while(a.v[item]==0)item++;
        if(a.cnt=3*(len-2)){
            printf("0.");
            for(int k=a.cnt-1;k>=item;k--)printf("%d",a.v[k]);
        }
        else if(a.cnt<3*(len-2)){
            int k=3*(len-2)-a.cnt;
            printf("0.");
            while(k-->0)printf("0");
            for(int k=a.cnt-1;k>=item;k--)printf("%d",a.v[k]);
        }
        else{
            printf("%d.",a.v[a.cnt-1]);
            for(int k=a.cnt-2;k>=item;k--)printf("%d",a.v[k]);
        }
        printf("\n");
    }
    return 0;
}