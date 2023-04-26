#include<stdio.h>
#include<string.h>
#include<malloc.h>
int cnt;
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
BigInt transform(char *s1){
    BigInt a1;
     a1.cnt=strlen(s1);
    for(int i=strlen(s1)-1;i>=0;i--)a1.v[a1.cnt-i-1]=*(s1+i)-'0';
    return a1;
}
void mod_reverse_trans(BigInt a,int *a1){
    BigInt b={0,{0}},two,c={0,{0}};

    two=Int2Big(2);
    int i=0,result,p=334;
    while(i<334){
        c.cnt=a.cnt;
        for(int k=a.cnt-1;k>=0;k--)c.v[k]=a.v[k];
        result=c.v[0]%2;
        a1[i]=result;
        result=0;
        for(int k=c.cnt-1;k>=0;k--){
            a.v[k]=(10*result+c.v[k])/2;
            result=(10*result+c.v[k])%2;
        }
        i++;
    }
    while(a1[p]==0)p--;
    i=0;
    cnt=p;
    while(i<p){
        int k=a1[i];
        a1[i]=a1[p];
        a1[p]=k;
        i++;
        p--;
    }
    return a1;
}

int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        char s[101];
        scanf("%s",s);
        BigInt a={0,{0}},b={0,{0}};
        int q[334];
        a=transform(s);
        mod_reverse_trans(a,q);
        BigInt two=Int2Big(2);
        for(int i=0;i<cnt;i++)if(q[i])b=add(b,Pow(i,two));
        printf("case #%d:\n",i);
        for(int k=b.cnt-1;k>=0;k--)printf("%d",b.v[k]);
        printf("\n");

    }
    return 0;
}