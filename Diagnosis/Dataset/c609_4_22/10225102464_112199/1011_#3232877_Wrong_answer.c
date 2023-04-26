#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int gcd(int a,int b)
{
    return a?gcd(b%a,a):b;
}
int main()
{
    char a[50];
    gets(a);
    a[strlen(a)]='\0';
    int i,xiao_1,xiao_2=0;
    long long zheng=0;
    for(i=0;i<strlen(a);i++){
        if(a[i]!='.'){
            int trye=0;
            if(a[i]>'0')
                trye=a[i]=='2'?-1:1;
            zheng+=trye;
            if(a[i+1]!='.'&&a[i+1]!=' '&&a[i+1]!='\n'&&a[i+1]!='\0') zheng*=3;
        }
        else break;
    }
    if(a[i]=='.'){
            xiao_2=pow(3,strlen(a)-i-1);
        for(int j=strlen(a)-1,y=0;j>i;j--,y++){
                if(a[j]=='2') xiao_1-=pow(3,y);
                    else if(a[j]!='0') xiao_1+=pow(3,y);

        }
        int pp=gcd(abs(xiao_1),abs(xiao_2));
        xiao_1=xiao_1/pp;
        xiao_2=xiao_2/pp;
    }

    if(xiao_1<0&&zheng>0){
        zheng--;
        xiao_1=-xiao_1;
        xiao_1=xiao_2-xiao_1;
    }
    else if(xiao_1>0&&zheng<0){
        zheng++;
        xiao_1=xiao_2-xiao_1;
    }
    if(zheng||xiao_2){
        if(zheng) printf("%lld ",zheng);
        if(xiao_2)printf("%lld %lld",xiao_1,xiao_2);
    }
    else printf("0");
    return 0;
}
