#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef struct{
    int cnt,v[500];
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
    int len=strlen(s);
    a.cnt=len;
    for(int i=len-1;i>=0;i--)a.v[len-i-1]=*(s+i)-'0';
    return a;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        char s[101]={0};
        int pre;
        scanf("%s",s);
        BigInt a=transform(s),one=Int2Big(1);
        for(int q=a.cnt;q<500;q++)a.v[q]=0;
        a=add(a,one);
        if(a.cnt==1)printf("case #%d:\n%d\n",i,a.v[a.cnt-1]);
        else{
            pre=a.v[a.cnt-1];
            int k =a.cnt-2;
            while(k>=0){
                if(a.v[k]!=pre){pre=a.v[k];k--;}
                else{
                    BigInt q={k+1,{0}};
                    q.v[q.cnt-1]=1;
                    a=add(a,q);
                    for(int s=k-1;s>=0;s--)a.v[s]=0;
                    pre=a.v[a.cnt-1];
                    k=a.cnt-2;
                }
            }
            printf("case #%d:\n",i);
            for(int k=a.cnt-1;k>=0;k--)printf("%d",a.v[k]);
            printf("\n");
        }
    }
    return 0;
}