#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define N 15
#define M 105

typedef struct
{
    int sup;   //record the top of stack
    double stk[N];
}Mystack;

void push(Mystack* m,double n)
{
    int index=m->sup;
    m->stk[index]=n;
    m->sup++;
}

double pop(Mystack* m)
{
    m->sup--;
    int index=m->sup;
    return m->stk[index];
}

int isDouble(char* s)
{
    for(int i=0;i<strlen(s);++i){
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')return 0;
    }
    return 1;
}

double trans(char* s)
{
    double ret=0;
    if(strchr(s,'.')==NULL){
        for(int i=0;i<strlen(s);++i)ret=ret*10+s[i]-'0';
    }
    else{
        for(int i=0;i<strlen(s);++i){
            if(s[i]!='.')ret=ret*10+s[i]-'0';
        }
        int cnt=0;
        for(int j=strlen(s)-1;s[j]!='.';--j)cnt++;
        //printf("%d\n",cnt);
        for(int k=0;k<cnt;++k)ret/=10;
    }
    return ret;
}

int main()
{
    int T;scanf("%d\n",&T);
    for(int i=0;i<T;++i){
        char input[M]={0};
        char t[M][N];
        for(int i=0;i<M;++i){
            for(int j=0;j<N;++j)t[i][j]='\0';
        }
        gets(input);
        int ti=0,tj=0;
        for(int i=0;i<strlen(input);++i){
            if(input[i]!=' ')t[ti][tj++]=input[i];
            else{ti++;tj=0;}
        }
        //for(int j=0;j<=ti;++j)printf("%s",t[j]);
        Mystack num;  //num is a stack
        num.sup=0;
        for(int i=0;i<N;++i)num.stk[i]=0.00;
        //printf("%.6lf\n",num.stk[0]);
        while(ti>-1){
            if(isDouble(t[ti])){   // isDouble -> whether a string can be a double
                double temp=trans(t[ti]);    // trans is used to turn a string to double
                push(&num,temp);
            }
            else{
                double left=pop(&num);
                double right=pop(&num);
                if(strcmp(t[ti],"+")==0)push(&num,left+right);
                if(strcmp(t[ti],"-")==0)push(&num,left-right);
                if(strcmp(t[ti],"*")==0)push(&num,left*right);
                if(strcmp(t[ti],"/")==0)push(&num,left/right);
            }
            ti--;
        }
        printf("case #%d:\n",i);
        printf("%.6lf\n",num.stk[0]);
    }
    return 0;
}