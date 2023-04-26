#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 105

void reverse(char* s)
{
    for(int i=0,j=strlen(s)-1;i<j;++i,--j){
        char temp=s[i];s[i]=s[j];s[j]=temp;
    }
}

char* eraseadd(char* s)
{
    char* ret=(char*)malloc(N);
    for(int i=0;i<N;++i)ret[i]=0;
    if(s[0]=='+'){
        for(int i=0,j=1;j<strlen(s);++i,++j){
            ret[i]=s[j];
        }
    }
    else strcpy(ret,s);
    return ret;
}

char* stoi(int n)
{
    char* ret=(char*)malloc(6);
    for(int i=0;i<6;++i)ret[i]=0;
    if(n==0){
        strcpy(ret,"0");
        return ret;
    }
    int p=0,flag=0;
    if(n<0){flag=1;n=-n;}
    while(n){
        ret[p++]=n%10+'0';
        n/=10;
    }
    if(flag)ret[p++]='-';
    else ret[p++]='+';
    reverse(ret);return ret;
}

char* solve(int xi,int ci)
{
    char* ret=(char*)malloc(10);
    char x[10],c[10];
    for(int i=0;i<10;++i)ret[i]=x[i]=c[i]=0;
    if(xi==1)strcat(ret,"+x");
    else if(xi==-1){strcat(ret,"-x");}
    else {
        strcat(ret,stoi(xi));
        strcat(ret,"x");
    }
    if(ci!=1){
        strcat(ret,"^");
        strcat(ret,eraseadd(stoi(ci)));
    }
    return ret;
}

int main()
{
    int T,x=0;
    scanf("%d",&T);
    while(x<T){
        int input[9]={0};
        char ret[N],s[N];
        for(int i=0;i<N;++i)ret[i]=s[i]=0;
        for(int i=8;i>-1;--i)scanf("%d",&input[i]);
        for(int i=8;i>0;--i){
            if(input[i]==0)continue;
            strcat(ret,solve(input[i],i));
        }
        if(input[0])strcat(ret,stoi(input[0]));
        strcpy(s,eraseadd(ret));
        if(strlen(s)==0)s[0]='0';
        printf("case #%d:\n",x);
        printf("%s\n",s);
        x++;
    }
    return 0;
}
