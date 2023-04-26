#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 105
#define M 55

int xishu(char* s)
{
    int flag=1,p=0,ret=0;
    if(s[p]=='-'){p++; flag=-1;}
    if(s[p]=='x')return flag;
    while(p<strlen(s)&&s[p]!='x'){
        ret=ret*10+s[p]-'0';
        ++p;
    }
    return ret*flag;
}

int findzhi(char* s)
{
    int ret=-1;
    for(int i=0;i<strlen(s);++i){
        if(s[i]=='^')ret=i;
    }
    if(ret>-1)return ret;
    else{
        for(int i=0;i<strlen(s);++i){
            if(s[i]=='x')ret=-2;
        }
    }
    return ret;
}

int zhishu(char* s)
{
    int ret=0;
    if(findzhi(s)==-2)return 1;
    else if(findzhi(s)==-1)return 0;
    else{
        int p=findzhi(s)+1;
        while(p<strlen(s))ret=ret*10+s[p++]-'0';
    }
    return ret;
}

int main()
{
    char s1[N],s2[N];
    for(int i=0;i<N;++i)s1[i]=s2[i]=0;
    while(scanf("%s %s",s1,s2)!=EOF){
    int n1=strlen(s1),n2=strlen(s2);
    char divide1[N][N],divide2[N][N];
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j)divide1[i][j]=divide2[i][j]=0;
    }
    int pi1=0,pj1=0,pi2=0,pj2=0;
    divide1[0][pj1++]=s1[0];divide2[0][pj2++]=s2[0];
    for(int i=1;i<n1;++i){
        if(s1[i]=='+'||s1[i]=='-'){
            pi1++;pj1=0;
            if(s1[i]=='-')divide1[pi1][pj1++]='-';
        }
        else divide1[pi1][pj1++]=s1[i];
    }
    for(int i=1;i<n2;++i){
        if(s2[i]=='+'||s2[i]=='-'){
            pi2++;pj2=0;
            if(s2[i]=='-')divide2[pi2][pj2++]='-';
        }
        else divide2[pi2][pj2++]=s2[i];
    }

    //for(int i=0;i<=pi1;++i)printf("%s\n",divide1[i]);

    int x1[M],x2[M];int ret[2*M];
    for(int i=0;i<M;++i)x1[i]=x2[i]=0;
    for(int i=0;i<=pi1;++i){
        x1[zhishu(divide1[i])]=xishu(divide1[i]);
    }
    for(int i=0;i<=pi2;++i){
        x2[zhishu(divide2[i])]=xishu(divide2[i]);
    }
    //for(int i=0;i<=10;++i)printf("%d %d\n",x1[i],x2[i]);
    //printf("%d\n",xishu("x^2"));
    for(int i=0;i<M*2;++i)ret[i]=0;
    for(int i=0;i<M;++i){
        for(int j=0;j<M;++j){
            ret[i+j]+=x1[i]*x2[j];
        }
    }
    for(int i=M*2-1;i>=0;--i){
        if(ret[i]!=0)printf("%d ",ret[i]);
    }
    printf("\n");
    }
    return 0;

}