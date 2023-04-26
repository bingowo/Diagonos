#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct{
    int cnt,v[1005],flag;
}BigInt;
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
    if(a<0)r.flag=-1;
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
void binary(char *c,char *s){
    char tab[16][5]={"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"},*s1,m;
    s1=s;
    if(*c=='0'){*s1='0';s1++;}
    else{
        if(isdigit(*c)&&*c-'0'<2){*s1=tab[*c-'0'][3];s1++;}
        else if(isdigit(*c)&&*c-'0'<4){*s1=tab[*c-'0'][2];*(s1+1)=tab[*c-'0'][3];s1=s1+2;}
        else if(isdigit(*c)&&c-'0'<8){*s1=tab[*c-'0'][1];*(s1+2)=tab[*c-'0'][2];*(s1+3)=tab[*c-'0'][3];s1=s1+3;}
        else if(isdigit(*c)){*s1=tab[*c-'0'][0];*(s1+1)=tab[*c-'0'][1];*(s1+2)=tab[*c-'0'][2];*(s1+3)=tab[*c-'0'][3];s1=s1+4;}
        else {*s1=tab[*c-'A'+10][0],*(s1+1)=tab[*c-'A'+10][1],*(s1+2)=tab[*c-'A'+10][2],*(s1+3)=tab[*c-'A'+10][3];s1=s1+4;}
        c++;
        if(*c){
        do{
            if(isdigit(*c)){*s1=tab[*c-'0'][0];*(s1+1)=tab[*c-'0'][1];*(s1+2)=tab[*c-'0'][2];*(s1+3)=tab[*c-'0'][3];}
            else {*s1=tab[*c-'A'+10][0],*(s1+1)=tab[*c-'A'+10][1],*(s1+2)=tab[*c-'A'+10][2],*(s1+3)=tab[*c-'A'+10][3];}
            s1=s1+4;
            c++;
            }
        while(*c);
        }
    }
    *s1=0;
}
int main(){
    BigInt zero=Int2Big(0);
    BigInt a=zero,a1=zero,b=zero,b1=zero,d;
    int m;
    char s[4000],c[10000],*s1,sign;
    scanf("%s",c);
    binary(c+2,s);
    s1=s;
    for(;*s1;s1++){
        d=Int2Big(*s1-'0');
        a=Sub(Sub(d,a1),b1);
        b=Sub(a1,b1);
        a1=a;
        b1=b;
    }
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