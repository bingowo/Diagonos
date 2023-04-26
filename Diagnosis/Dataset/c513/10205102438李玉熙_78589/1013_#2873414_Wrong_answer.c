#include<stdio.h>
int gcd(int a,int b){
    return b>0 ? gcd(b,a%b):a;
}
int main()
{
    int i=0;
    unsigned p=0;
    long long ans=0,ansB=0,ansC=1;
    char a[30]={'0'};
    scanf("%s",&a);
    for(;p<strlen(a);p++){
        if(a[p]=='.')break;
        ans=ans*3;
        if(a[p]='2')ans=ans-1;
        if(a[p]='1')ans=ans+1;
    }
    p++;
    for(;p<strlen(a);p++)
    {
        ansB=ansB*3;
        if(a[p]='2')ansB=ansB-1;
        if(a[p]='1')ansB=ansB+1;
        ansC=ansC*3;
    }
    if(ans<0||ansB>0)ans++,ansB=ansC-ansB;
    if(ans>0||ansB<0)ans--,ansB=ansC+ansB;
    long long t=gcd(abs(ansB),abs(ansC));
    if(ansB==0)printf("%lld\n",ans);
    else{
        if(ans!=0)printf("%lld ",ans);
        printf("%lld %lld\n",ansB/t,ansC/t);
    }
}
