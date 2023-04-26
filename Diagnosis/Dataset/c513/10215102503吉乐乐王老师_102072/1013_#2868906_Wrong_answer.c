#include<stdio.h>
#include<string.h>
int get(int base,int digit){
    int ret=1;
    while(digit--){
        ret*=base;
    }
    return ret;
}
int gcd(int a,int b){
    if(a>b)return a%b==0?b:gcd(b,a%b);
    gcd(b,a);
}
int main(){
    char s[50];
    scanf("%s",s);
    int idx=0;
    char zheng[20],fen[20];
    int i,j;i=j=0;
    while(s[idx]){
        zheng[i++]=s[idx++];
        if(s[idx]=='.'){
            while(s[++idx])fen[j++]=s[idx];
        }
    }
    int zhengshu=0,fenshu=0,cnti=i,cntj=j;
    for(int p=0;p<cnti;p++){
        if(zheng[p]=='1')zhengshu+=get(3,i-1);
        if(zheng[p]=='2')zhengshu-=get(3,i-1);
        i--;
    }
    for(int p=0;p<cntj;p++){
        if(fen[p]=='1')fenshu+=get(3,j-1);
        if(fen[p]=='2')fenshu-=get(3,j-1);
        j--;
    }
    int GCD;
    if(fenshu!=0){if(fenshu<0){fenshu+=get(3,cntj),zhengshu-=1;zhengshu=-zhengshu;};GCD=gcd(fenshu,get(3,cntj));}
    if(zhengshu==0&&fenshu!=0)printf("%d %d",fenshu/GCD,get(3,cntj)/GCD);
    else if(zhengshu!=0&&fenshu==0)printf("%d",zhengshu);
    else printf("%d %d %d",zhengshu,fenshu/GCD,get(3,cntj)/GCD);
}