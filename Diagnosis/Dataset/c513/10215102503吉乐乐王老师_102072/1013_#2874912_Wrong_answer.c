#include<stdio.h>
#include<string.h>
int gcd(int a,int b){
    if(a<0)a=-a;if(b<0)b=-b;
    if(a>b)return a%b==0?b:gcd(b,a%b);
    gcd(b,a);
}
int main(){
    char s[50];
    int p=0;
    scanf("%s",s);
    long long int zhengshu=0,fenzi=0,fenmu=1;
    for(;p<strlen(s);p++){
        if(s[p]=='.')break;
        zhengshu*=3;
        if(s[p]=='1')zhengshu+=1;
        if(s[p]=='2')zhengshu-=1;
    }
    for(;p<strlen(s);p++){
        fenzi*=3;
        if(s[p]=='1')fenzi+=1;
        if(s[p]=='2')fenzi-=1;
        fenmu*=3;
    }
    long long int GCD;
    if(fenzi!=0){
        if(fenzi<0&&zhengshu>0){
            fenzi+=fenmu,zhengshu-=1;}
        if(fenzi<0&&zhengshu<0){
            fenzi=-fenzi;zhengshu=-zhengshu;
        }
        if(fenzi>0&&zhengshu<0){
            fenzi=fenmu-fenzi;zhengshu+=1;
        }
        GCD=gcd(fenzi,fenmu);
    }
    if(zhengshu==0&&fenzi!=0){printf("%lld %lld",fenzi/GCD,fenmu/GCD);}
    else if(zhengshu!=0&&fenzi==0)printf("%d",zhengshu);
    else if(zhengshu==0&&fenzi==0)printf("0");
    else printf("%lld %lld %lld",zhengshu,fenzi/GCD,fenmu);
}