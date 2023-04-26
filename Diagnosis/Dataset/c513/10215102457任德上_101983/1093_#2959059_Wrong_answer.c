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
int mod(BigInt a,int b){
    int k=0;
    for(int i=a.cnt-1;i>=0;i--){
        k=a.v[i]%b;
        a.v[i-1]+=10*k;
    }
    return k;
}
int find_nine(BigInt a){
    for(int i=a.cnt-1;i>=0;i--)if(a.v[i]==9)return 1;
    return 0;
}
int main(){
    char s[101];
    scanf("%s",s);
    BigInt a,b,c,one=Int2Big(1);
    a=transform(s);
    a=add(a,one);
    while(1){
        if(find_nine(a)==0&&mod(a,9)!=0)break;
        a=add(a,one);
    }
    for(int i=a.cnt-1;i>=0;i--)printf("%d",a.v[i]);
    return 0;
}