#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#define N 85

/** Equation  **/

int xishu(char s[])
{
    int ret=0,p=0,sign=1;
    if(strlen(s)==1&&isalpha(s[0]))return 1;
    if(strlen(s)==2&&isalpha(s[1])){
        if(s[0]=='-')return -1;
        if(s[0]=='+')return 1;
    }

    if(s[0]=='+'||s[0]=='-'){
        p++;
        if(s[0]=='-')sign=-1;
    }
    for(int i=p;s[i]<='9'&&s[i]>='0';++i){
        ret=ret*10+s[i]-'0';
    }
    return ret*sign;
}

int cont(char s[])
{
    for(int i=0;i<strlen(s);++i){
        if(isalpha(s[i]))return 1;
    }
    return 0;
}

int sum(int a[],int n)
{
    int ret=0;
    for(int i=0;i<=n;++i){
        ret+=a[i];
    }
    return ret;
}

int main()
{
    char input[N]={0};
    scanf("%s",input);
    char w; int mid;
    for(int i=0;i<strlen(input);++i){
        if(input[i]>='a'&&input[i]<='z'){
            w = input[i];
        }
        if(input[i]=='=')mid = i;
    }
    char left[25][10],right[25][10];
    for(int i=0;i<25;++i){
        for(int j=0;j<10;++j)
            left[i][j]=right[i][j]=0;
    }
    int li=0,lj=0,ri=0,rj=0;
    for(int i=0;i<mid;++i){
        if(input[i]=='-'||input[i]=='+'){
            li++;lj=0;
            left[li][lj++]=input[i];
        }
        else{
            left[li][lj++]=input[i];
        }
    }
    int left_xi[25],left_wei[25];
    int right_xi[25],right_wei[25];
    for(int i=0;i<25;++i){
        left_wei[i]=left_xi[i]=right_wei[i]=right_xi[i]=0;
    }
    int lx=0,lw=0;
    for(int i=0;i<=li;++i){
        if(cont(left[i]))left_wei[lw++]=xishu(left[i]);
        else left_xi[lx++]=xishu(left[i]);
    }
    for(int i=mid+1;i<strlen(input);++i){
        if(input[i]=='-'||input[i]=='+'){
            ri++;rj=0;
            right[ri][rj++]=input[i];
        }
        else{
            right[ri][rj++]=input[i];
        }
    }

    int rx=0,rw=0;
    for(int i=0;i<=ri;++i){
        if(cont(right[i]))right_wei[rw++]=xishu(right[i]);
        else right_xi[rx++]=xishu(right[i]);
    }
    double a = sum(left_wei,lw)-sum(right_wei,rw);
    double b = sum(right_xi,rx)-sum(left_xi,lx);
    printf("%c=%.3lf",w,b/a);

    return 0;

}