#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define N 26
#define M 20

typedef struct
{
    char name[3];
    int val;
}variable;

int Read(char* s)
{
    if(!strcmp(s,"IN"))return 1;
    if(!strcmp(s,"MOV"))return 2;
    if(!strcmp(s,"ADD"))return 3;
    if(!strcmp(s,"SUB"))return 4;
    if(!strcmp(s,"MUL"))return 5;
    if(!strcmp(s,"DIV"))return 6;
    if(!strcmp(s,"OUT"))return 7;
    if(!strcmp(s,"XCHG"))return 8;
    if(!strcmp(s,"MOD"))return 9;
    if(!strcmp(s,"AND"))return 10;
    if(!strcmp(s,"OR"))return 11;
    if(!strcmp(s,"XOR"))return 12;
    return -1;
}

int findvi(variable v[],char* tag)
{
    for(int i=0;i<N;++i){
        if(strcmp(v[i].name,tag)==0)return i;
    }
    return -1;
}

int getdou(char* s)
{
    int n=strlen(s);
    for(int i=0;i<n;++i){
        if(s[i]==',')return i;
    }
    return -1;
}

char* cut(char* s,int begin,int end)
{
    char* ret=(char*)malloc(M/2);
    for(int i=0;i<M/2+1;++i)ret[i]=0;
    for(int r=0,k=begin;k<end;++k,++r){
        ret[r]=s[k];
    }
    return ret;
}

int cntdou(char* s)
{
    int cnt=0;
    for(int i=0;i<M;++i){
        if(s[i]==',')cnt++;
    }
    return cnt;
}

int stoi(char* s)
{
    int ret=0,sign=1;
    int p=0;
    if(s[p]=='-'){p++; sign=-1;}
    while(p<strlen(s)){
        ret=ret*10+s[p++]-'0';
    }
    return ret*sign;
}

int main()
{
    variable v[N];
    for(int i=0;i<N;++i){
        v[i].val=0;
        for(int j=0;j<3;++j)v[i].name[j]=0;
    }
    char al[26][2];
    for(int i=0;i<26;++i){
        al[i][0]=i+'A';al[i][1]=0;
        strcat(v[i].name,al[i]);
        strcat(v[i].name,"X");
    }
    printf("%s",v[25].name);


    char input[M],re[M];
    for(int i=0;i<M;++i)input[i]=re[i]=0;

    while(scanf("%s%s",input,re)!=EOF)
    {

        int len=strlen(re);
        //int r=getdou(re);
        int ina=findvi(v,cut(re,0,2));
        int inb=findvi(v,cut(re,3,5));
        // IN
        if(Read(input)==1)
        {
            int value=stoi(cut(re,3,len));
            //printf("%d\n",value);
            v[ina].val=value;
        }
        // MOV
        if(Read(input)==2){
            v[ina].val=v[inb].val;
        }
        // ADD
        if(Read(input)==3){
            if(cntdou(re)==1)v[ina].val+=v[inb].val;
            if(cntdou(re)==2){
                int inc=findvi(v,cut(re,6,8));
                v[ina].val=v[inb].val+v[inc].val;
            }
        }
        // SUB
        if(Read(input)==4){
            if(cntdou(re)==1)v[ina].val-=v[inb].val;
            if(cntdou(re)==2){
                int inc=findvi(v,cut(re,6,8));
                v[ina].val=v[inb].val-v[inc].val;
            }
        }
        // MUL
        if(Read(input)==5){
            if(cntdou(re)==1)v[ina].val*=v[inb].val;
            if(cntdou(re)==2){
                int inc=findvi(v,cut(re,6,8));
                v[ina].val=v[inb].val*v[inc].val;
            }
        }
        //DIV
        if(Read(input)==6){
            if(cntdou(re)==1)v[ina].val/=v[inb].val;
            if(cntdou(re)==2){
                int inc=findvi(v,cut(re,6,8));
                v[ina].val=v[inb].val/v[inc].val;
            }
        }
        //OUT
        if(Read(input)==7){
            int t=findvi(v,cut(re,0,2));
            printf("%d\n",v[t].val);
        }
        if(Read(input)==8){
            int temp=v[ina].val;
            v[ina].val=v[inb].val;
            v[inb].val=temp;
        }
        if(Read(input)==9){
            if(cntdou(re)==1)v[ina].val%=v[inb].val;
            if(cntdou(re)==2){
                int inc=findvi(v,cut(re,6,8));
                v[ina].val=v[inb].val%v[inc].val;
            }
        }
        if(Read(input)==10){
            if(cntdou(re)==1)v[ina].val&=v[inb].val;
            if(cntdou(re)==2){
                int inc=findvi(v,cut(re,6,8));
                v[ina].val=v[inb].val&v[inc].val;
            }
        }
        if(Read(input)==11){
            if(cntdou(re)==1)v[ina].val|=v[inb].val;
            if(cntdou(re)==2){
                int inc=findvi(v,cut(re,6,8));
                v[ina].val=v[inb].val|v[inc].val;
            }
        }
        if(Read(input)==12){
            if(cntdou(re)==1)v[ina].val^=v[inb].val;
            if(cntdou(re)==2){
                int inc=findvi(v,cut(re,6,8));
                v[ina].val=v[inb].val^v[inc].val;
            }
        }
    }
    return 0;

}
