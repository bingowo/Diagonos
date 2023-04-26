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
        BigInt x,y,z;
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
        for(int i=z.cnt-1;i>=0;i--)printf("%d",z.v[i]);
    }
    return 0;
}