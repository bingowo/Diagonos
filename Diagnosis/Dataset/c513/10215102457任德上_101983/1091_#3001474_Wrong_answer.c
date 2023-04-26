#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
typedef struct{
    int cnt,v[2005],flag;
}BigInt;
BigInt a1,b1;
int compare(BigInt a,BigInt b,int c){
    if(a.cnt>b.cnt)return c;
    else if(a.cnt<b.cnt)return -c;
    else{
        for(int i=a.cnt-1;i>=0;i--){
            if(a.v[i]>b.v[i])return c;
            else if(a.v[i]<b.v[i])return -c;
        }
        return 0;
    }
}
int Compare(BigInt a,BigInt b){
    if(a.flag==1&&b.flag==-1)return 1;
    if(a.flag==-1&&b.flag==1)return -1;
    if(a.flag==1&&b.flag==1)return compare(a,b,1);
    else return compare(a,b,-1);
}
BigInt Int2Big(int a){
    BigInt r={0,{0},1};
    if(a<0){r.flag=-1;a=-a;}
    do{
        r.v[r.cnt++]=a%10;
        a/=10;
    }while(a>0);
    return r;
}
int compare1(BigInt a,BigInt b){
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
BigInt add(BigInt a,BigInt b,int c){
    int i=0;
    while(i<a.cnt||i<b.cnt){
        a.v[i]+=b.v[i];
        a.v[i+1]+=a.v[i]/10;
        a.v[i]%=10;
        i++;
    }
    a.cnt=i+1;
    while(a.v[a.cnt-1]==0)a.cnt--;
    a.flag=c;
    return a;
}
BigInt sub(BigInt a,BigInt b,int c){
    int i=0;
    while(i<a.cnt||i<b.cnt){
        a.v[i]=a.v[i]>=b.v[i]?a.v[i]-b.v[i]:a.v[i]-b.v[i]+10*(a.v[i+1]-(--a.v[i+1]));
        i++;
    }
    while(a.v[a.cnt-1]==0&&a.cnt>1)a.cnt--;
    a.flag=c;
    return a;
}
BigInt Add(BigInt a,BigInt b){
    if(a.flag==1&&b.flag==1)return add(a,b,1);
    if(a.flag==-1&&b.flag==-1)return add(a,b,-1);
    if(a.flag==1&&b.flag==-1){
           if(compare1(a,b)>=0)return sub(a,b,1);
           else return sub(b,a,-1);
    }
    if(compare1(a,b)>0)return sub(a,b,-1);
    else return sub(b,a,1);
}
BigInt Sub(BigInt a,BigInt b){
    if(a.flag==1&&b.flag==-1)return add(a,b,1);
    if(a.flag==-1&&b.flag==1)return add(a,b,-1);
    if(a.flag==1&&b.flag==1){
        if(compare1(a,b)>=0)return sub(a,b,1);
        else return sub(b,a,-1);
    }
    if(compare1(a,b)>0)return sub(a,b,-1);
    else return sub(b,a,1);
}
BigInt Mul(BigInt q,BigInt r){
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
    if(q.flag!=r.flag)key.flag=-1;
    else key.flag=1;
    return key;
}
void Pow(BigInt a,BigInt b,long long int k){
    if(k==0){a1=Int2Big(1),b1=Int2Big(0);}
    if(k==1){a1=a,b1=b;}
    BigInt c,a2,b2;
    a2=a,b2=b;
    for(int i=0;i<k-1;i++){
        c=Mul(b2,b);
        b2=Add(Mul(b2,a),Mul(a2,b));
        a2=Mul(a2,a);
        a2=Sub(a2,c);
    }
    a1=a2;
    b1=b2;
}
int R(long long int a,long long int b){
    if((a-b)%2!=0)return 1;
    return 0;
}
int main(){
    int sign,a3=0,b3=0;
    long long m,k;
    int flag1=0,flag2=0,flag3=0;
    char c;
    int n[1000];
    sign=1LL;
    while((c=getchar())!=' '){
        if(c=='-')sign=-1LL;
        else if(c=='+')sign=1LL;
        else if(c=='i'){
            flag1=1;
        }
        else{
            flag2++;
            int i=0;
            char num[20]={0};
            num[i++]=c;
             while(isdigit(c=getchar()))num[i++]=c;
             if(c=='i')flag2--;
            ungetc(c,stdin);
            m=sign*atoll(num);
            if(a3==0LL){a3=m;m=0LL;}
            else b3=m;
            sign=1LL;
        }
    }
    scanf("%lld",&k);
    if(flag1==1&&flag2==0&&a3!=0){b3=a3;a3=0;}
    else if((flag1==1&&flag2>=1&&b3==0)||(flag1==1&&flag2==0&&a3==0))b3=sign;
    BigInt a=Int2Big(a3),b=Int2Big(b3);
    Pow(a,b,k);
    a=a1,b=b1;
    if(b.cnt<=0)b.cnt=1;
    if(a.cnt<=0)a.cnt=1;
    BigInt zero=Int2Big(0);
    if(Compare(b,zero)<0){
        b.flag=1;
        sign='-';
    }
    else if(Compare(b,zero)>0)sign='+';
    else sign=0;
    if(Compare(a,zero)!=0){
    if(compare1(b,Int2Big(1))!=0){
        if(a.flag<0)printf("-");
        for(int i=a.cnt-1;i>=0;i--)printf("%d",a.v[i]);
        printf("%c",sign);
        if(sign){for(int i=b.cnt-1;i>=0;i--)printf("%d",b.v[i]); printf("i");}

    }
    else if(Compare(b,zero)!=0){
        if(a.flag<0)printf("-");
        for(int i=a.cnt-1;i>=0;i--)printf("%d",a.v[i]);
        printf("%c",sign);
        if(sign)printf("i");
    }
    else {if(a.flag<0)printf("-");for(int i=a.cnt-1;i>=0;i--)printf("%d",a.v[i]);}
    }
    else{
        if(Compare(b,zero)==0){if(a.flag<0)printf("-");for(int i=a.cnt-1;i>=0;i--)printf("%d",a.v[i]);}
        else if(compare1(b,Int2Big(1))!=0){if(sign!='+')printf("%c",sign);for(int i=b.cnt-1;i>=0;i--)printf("%d",b.v[i]);printf("i");}
        else {if(sign!='+'&&sign!=0)printf("%c",sign);printf("i");}
    }
    return 0;
}