#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
    int cnt,v[1000];
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
    int i=0,carry=0,max;
    max=a.cnt>b.cnt?a.cnt:b.cnt;
    BigInt c={max,{0}};
    while(i<a.cnt||i<b.cnt){
        int t=a.v[i]+b.v[i]+carry;
        c.v[i]=t%10;
        carry=t/10;
        i++;
    }
    if(carry>0)c.v[i]=carry;
    c.cnt=i+1;
    while(c.v[c.cnt-1]==0)c.cnt--;
    return c;
}
void split(BigInt *a1,BigInt *a2,char *s1){
    char *s,*c;
    s=s1;
    c=strchr(s1,'.');
    if(c==s1){
        a2->cnt=500;
        for(int i=strlen(s1)-1;i>0;i--)a2->v[a2->cnt-i]=*(s+i)-'0';
    }
    else if(c==s1+strlen(s1)-1){
        a1->cnt=strlen(s1)-1;
        for(int i=strlen(s1)-1;i>0;i--)a1->v[a1->cnt-i]=*(s+i-1)-'0';
    }
    else{
        *c=0;
        a1->cnt=strlen(s);
        for(int i=strlen(s)-1;i>=0;i--)a1->v[a1->cnt-i-1]=*(s+i)-'0';
        s=c+1;
        *c='.';
        a2->cnt=500;
        for(int i=strlen(s)-1;i>=0;i--)a2->v[a2->cnt-i-1]=*(s+i)-'0';

    }
}
int main(){
    char s1[1001],s2[1001];
    int n;
    BigInt a1={0,{0}},a2={0,{0}},b1={0,{0}},b2={0,{0}},c1,c2,c3={0,{0}},car;
    BigInt *A1,*A2,*B1,*B2;
    A1=&a1,A2=&a2,B1=&b1;B2=&b2;
    scanf("%s%s%d",s1,s2,&n);
    if(strchr(s1,'.')!=NULL)split(A1,A2,s1);
    else a1=Int2Big(atoi(s1));
    if(strchr(s2,'.')!=NULL)split(B1,B2,s2);
    else b1=Int2Big(atoi(s2));
    int max=500,carry=0;
    c1=add(a1,b1);
    c2=add(a2,b2);
    if(c2.v[c2.cnt-n-1]>=5){
        c3.cnt=c2.cnt-n+1;
        c3.v[c3.cnt-1]=1;
        for(int i=0;i<c2.cnt-n-1;i++)c2.v[i]=0;
        c2=add(c2,c3);
    }
    if(c2.cnt>max){carry=c2.v[c2.cnt-1],c2.v[c2.cnt-1]=0;c2.cnt--;}
    car=Int2Big(carry);
    c1=add(car,c1);
    for(int i=c1.cnt-1;i>=0;i--)printf("%d",c1.v[i]);
    printf(".");
    for(int i=c2.cnt-1;i>=c2.cnt-n;i--)printf("%d",c2.v[i]);
    return 0;
}