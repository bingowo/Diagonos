#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define N 4
#define M 20

typedef struct
{
    char name[3];
    int val;
}variable;

int Read(char* s)
{
    if(s[0]=='I'&&s[1]=='N')return 1;
    if(s[0]=='M'&&s[1]=='O'&&s[2]=='V')return 2;
    if(s[0]=='A'&&s[1]=='D'&&s[2]=='D')return 3;
    if(s[0]=='S'&&s[1]=='U'&&s[2]=='B')return 4;
    if(s[0]=='M'&&s[1]=='U'&&s[2]=='L')return 5;
    if(s[0]=='D'&&s[1]=='I'&&s[2]=='V')return 6;
    if(s[0]=='O'&&s[1]=='U'&&s[2]=='T')return 7;
    return -1;
}

int findvi(variable v[],char* tag)
{
    for(int i=0;i<N;++i){
        if(strcmp(v[i].name,tag)==0)return i;
    }
    return -1;
}

int getspace(char* s)
{
    int n=strlen(s);
    for(int i=0;i<n;++i){
        if(s[i]==' ')return i;
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
    strcpy(v[0].name,"AX");
    strcpy(v[1].name,"BX");
    strcpy(v[2].name,"CX");
    strcpy(v[3].name,"DX");

    char input[M];
    for(int i=0;i<M;++i)input[i]=0;
    
    while(gets(input)!=EOF)
    {
        //printf("%s\n",input);
        int len=strlen(input);
        int l=getspace(input);
        int r=getdou(input);
        int ina=findvi(v,cut(input,l+1,r));
        int inb=findvi(v,cut(input,r+1,len));
        // IN
        if(Read(input)==1)
        {
            int value=stoi(cut(input,r+1,len));
            //printf("%d\n",value);
            //printf("%d %d\n",l,r);
            v[ina].val=value;
        }
        // MOV
        if(Read(input)==2)v[ina].val=v[inb].val;
        // ADD
        if(Read(input)==3)v[ina].val+=v[inb].val;
        // SUB
        if(Read(input)==4)v[ina].val-=v[inb].val;
        // MUL
        if(Read(input)==5)v[ina].val*=v[inb].val;
        //DIV
        if(Read(input)==6)v[ina].val/=v[inb].val;
        //OUT
        if(Read(input)==7){
            int t=findvi(v,cut(input,l+1,len));
            printf("%d\n",v[t].val);
        }
        for(int i=0;i<M;++i)input[i]=0;
    }
    printf("2\n");
    return 0;

}
