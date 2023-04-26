#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
long long int a1,b1;
void Pow(long long int a,long long int b,long long int k){
    if(k==0){a1=1LL,b1=0LL;}
    if(k==1){a1=a,b1=b;}
    long long int c,a2,b2;
    a2=a,b2=b;
    for(int i=0;i<k-1;i++){
        c=b2*b;
        b2=b2*a+a2*b;
        a2=a2*a;
        a2=a2-c;
    }
    a1=a2;
    b1=b2;
}
int R(long long int a,long long int b){
    if((a-b)%2!=0)return 1;
    return 0;
}
int main(){
    long long int sign,a=0LL,b=0LL,m,k;
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
            if(a==0LL){a=m;m=0LL;}
            else b=m;
            sign=1LL;
        }
    }
    scanf("%lld",&k);
    if(flag1==1&&flag2==0&&a!=0LL){b=a;a=0LL;}
    else if((flag1==1&&flag2>=1&&b==0LL)||(flag1==1&&flag2==0&&a==0LL))b=sign;
    Pow(a,b,k);
    if(b1<0LL){
        b=-b;
        sign='-';

    }
    else if(b1>0LL)sign='+';
    else sign=0LL;
    if(a1!=0LL){
    if(b1!=1LL&&b1!=-1LL){printf("%lld",a1);printf("%c",sign);if(sign)printf("%lldi",b1);}
    else if(b1!=0LL){printf("%lld",a1);printf("%c",sign);if(sign)printf("i");}
    else printf("%lld",a1);}
    else{
        if(b1==0LL)printf("%lld",a1);
        else if(b1!=1LL&&b1!=-1LL   ){if(sign!='+')printf("%c",sign);printf("%lldi",b1);}
        else {if(sign!='+'&&sign!=0LL)printf("%c",sign);printf("i");}
    }
    return 0;

}