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
BigInt sub(BigInt a,BigInt b){
    int flag=1,i=0;
    if(a.cnt>b.cnt)flag=1;
    else if(a.cnt<b.cnt)flag=-1;
    else{
        int i=a.cnt;
        while(i>=0){
            if(a.v[i]!=b.v[i]){
                flag=a.v[i]>b.v[i]?1:-1;
                break;
            }
            i--;
        }
    }
    if(flag==1){
        while(i<a.cnt||i<b.cnt){
            a.v[i]=a.v[i]>=b.v[i]?a.v[i]-b.v[i]:a.v[i]-b.v[i]+10*(a.v[i+1]-(--a.v[i+1]));
            i++;
        }
        while(a.v[a.cnt-1]==0&&a.cnt>1)a.cnt--;
        return a;
    }
    else{
        while(i<a.cnt||i<b.cnt){
            b.v[i]=b.v[i]>=a.v[i]?b.v[i]-a.v[i]:b.v[i]-a.v[i]+10*(b.v[i+1]-(--b.v[i+1]));
            i++;
        }
        while(b.v[b.cnt-1]==0&&b.cnt>1)b.cnt--;
        return b;
    }
}
int main(){
    int n;
    while(scanf("%d",&n)){
        if(n==-1)break;
        BigInt a,b,c;
        if(n==1)printf("2\n");
        else if(n==2)printf("4\n");
        else{
            a=Int2Big(2);
            a=Pow(n,a);        //总的可能数
            b=Int2Big(n-2);    //所选的可能数
            c=Int2Big(2);
            c=Pow(n-3,c);
            b=mul(b,c);
            a=sub(a,b);
            for(int i=a.cnt-1;i>=0;i--)printf("%d",a.v[i]);
            printf("\n");
        }
    }
    return 0;
}