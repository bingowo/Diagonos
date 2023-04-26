#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 105

int R_num(long long real,long long vir)
{
    real=real>0?real:-real;
    vir=vir>0?vir:-vir;
    if(real%2==0&&vir%2==0)return 0;
    if(real%2==1&&vir%2==1)return 0;
    if(real%2==1&&vir%2==0)return 1;
    if(real%2==0&&vir%2==1)return 1;
}


void reverse(char* s)
{
    char temp;
    for(int i=0,j=strlen(s)-1;i<j;++i,--j){
        temp=s[i];s[i]=s[j];s[j]=temp;
    }
}

int findi(char* s)
{
    int index=-1;
    for(int i=0;i<strlen(s);++i){
        if(s[i]=='i')index=i;
    }
    return index;
}

long long strTolong(char* s,int l,int r)  // l<=i<r
{
    long long ret=0;long long sign=1;
    if(l==r)return 0;
    int p=l;
    if(s[p]=='-'){
        sign=-1;++p;
    }
    if(s[p]=='+'){
        sign=1;++p;
    }
    while(p<r){
        ret=ret*10+s[p++]-'0';
    }
    return sign*ret;
}

long long getReal(char* s)
{
    int len=strlen(s);int p=findi(s);
    if(p==-1)return strTolong(s,0,len);
    while(p>0&&s[p]!='+'&&s[p]!='-')p--;
    return strTolong(s,0,p);
}

long long getVir(char* s)
{
    int len=strlen(s);int p=findi(s);int sign=p;
    if(p==-1)return 0;
    if(p==0)return 1;if(s[p-1]=='+')return 1;if(s[p-1]=='-')return -1;
    while(p>0&&s[p]!='+'&&s[p]!='-')p--;
    long long ans= strTolong(s,p,sign);
    if(p>0&&s[p-1]=='-')ans*=-1;
    return ans;
}

void divide(long long* r,long long* v)
{
    long long a=*r;long long b=*v;
    int yu=R_num(a,b);
    if(yu==1)a--;
    *v=-(a+b)/2;
    *r=(b-a)/2;
}

int main()
{
    char s[N]={'\0'};
    char ret[N]={'\0'};
    scanf("%s",s);
    long long real=getReal(s);long long vir=getVir(s);
    //printf("%d",R_num(real,vir));
   // printf("%lld",real);
    int pret=0;
    while(real!=0||vir!=0){
        ret[pret++]=R_num(real,vir)+'0';
        divide(&real,&vir);
    }
    //divide(&real,&vir);divide(&real,&vir);divide(&real,&vir);divide(&real,&vir);
    //printf("%lld %lld",real,vir);
    reverse(ret);
    printf("%s",ret);
    return 0;
}
