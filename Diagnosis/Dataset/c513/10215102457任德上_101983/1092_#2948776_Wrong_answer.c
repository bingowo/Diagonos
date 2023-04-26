#include<stdio.h>
#include<string.h>
typedef struct{
    int cnt,v[1001];
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
        k=i+j;
        while(carry>0){
            int t=carry+key.v[k];
            key.v[k++]=t%10;
            carry=t/10;
    }
    }
    if(key.v[key.cnt-1]==0)key.cnt--;
    return key;
}
int main(){
    char s[1001];
    scanf("%s",s);
    int t=strlen(s);
    if(t==1)printf("1");
    else if(t==2)printf("4");
    else{
        t-=2;
        BigInt now,x;
        now=Int2Big(4);
        x=Int2Big(3);
        while(t-->0)now=mul(now,x);
        for(int i=now.cnt-1;i>=0;i--)printf("%d",now.v[i]);
    }
    return 0;
}