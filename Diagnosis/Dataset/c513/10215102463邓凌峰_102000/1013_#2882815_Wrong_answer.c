#include <stdio.h>
#include <stdlib.h>
#include <string.h>


long long gcd(long long x,long long y)//x<y
{
    long long ans=1;
    for(long long i=2;i<=x/2;i++){
        if(x%i==0 && y%i==0){ans=i;}
    }
    return ans;
}

int main()
{
    char num1[31]={'\0'},num2[31]={'\0'};
    char a;
    int cnt=0;
    while((a=getchar())!='.' && a!='\n'){num1[cnt++]=a;}
    int te=1;
    if(a=='\n'){te=0;}
    long long Sum=0,len=strlen(num1);
    long long max=pow(3,len-1);
    int i=0;
    for(;i<len;i++){
        if(num1[i]=='.'){i++;break;}
        if(num1[i]=='1') Sum+=max;
        else if(num1[i]=='0');
        else Sum-=max;
        max/=3;
    }
    cnt=0;
    long long fenzi=0,fenmu=1;
    if(te){
        while((a=getchar())!='.' && a!='\n'){num2[cnt++]=a;}
        len=strlen(num2);
        i=0;
        for(;i<len;i++){
            fenzi*=3;
            if(num2[i]=='1'){fenzi+=1;}
            if(num2[i]=='2'){fenzi-=1;}
            fenmu*=3;
        }
        long long t=gcd(abs(fenzi),fenmu);
        fenzi/=t;fenmu/=t;
    }
    if(Sum>0 && fenzi<0){Sum-=1;fenzi+=fenmu;}

    if(fenzi==0){printf("%lld ",Sum);}
    else{
        if(Sum!=0){printf("%lld ",Sum);}
        printf("%lld %lld",fenzi,fenmu);
    }

    return 0;
}





