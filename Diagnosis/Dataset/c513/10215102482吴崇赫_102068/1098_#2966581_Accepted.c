#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 105

int findc(char c,char* s,int begin)
{
    for(int i=begin;i<begin+4;++i){
        if(s[i]==c)return i;
    }
    return -1;
}

int isAlpha(char* s)
{
    for(int i=0;i<strlen(s);++i){
        if(s[i]>='Z'||s[i]<='A')return 0;
    }
    return 1;
}

void solve(char* s,int a)
{
    if(findc('R',s,a)>=0&&findc('Y',s,a)>=0&&findc('B',s,a)>=0&&findc('!',s,a)>=0){
        int t=findc('!',s,a);
        s[t]='G';
    }
    else if(findc('R',s,a)>=0&&findc('Y',s,a)>=0&&findc('G',s,a)>=0&&findc('!',s,a)>=0){
        int t=findc('!',s,a);
        s[t]='B';
    }
    else if(findc('R',s,a)>=0&&findc('B',s,a)>=0&&findc('G',s,a)>=0&&findc('!',s,a)>=0){
        int t=findc('!',s,a);
        s[t]='Y';
    }
    else if(findc('B',s,a)>=0&&findc('Y',s,a)>=0&&findc('G',s,a)>=0&&findc('!',s,a)>=0){
        int t=findc('!',s,a);
        s[t]='R';
    }
}

int main()
{
    int T,x=0;
    scanf("%d\n",&T);
    while(x<T){
        char s[N],temp[N];
        for(int i=0;i<N;++i)s[i]=temp[i]=0;
        scanf("%s",s);
        strcpy(temp,s);
        while(!isAlpha(s)){
            for(int i=0;i<strlen(s)-3;++i){
                solve(s,i);
            }
        }
        printf("case #%d:\n",x++);
        //printf("%s\n",s);
        int R=0,B=0,Y=0,G=0;
        for(int k=0;k<strlen(s);++k){
            if(temp[k]=='!'&&s[k]=='R')R++;
            if(temp[k]=='!'&&s[k]=='B')B++;
            if(temp[k]=='!'&&s[k]=='Y')Y++;
            if(temp[k]=='!'&&s[k]=='G')G++;
        }
        printf("%d %d %d %d\n",R,B,Y,G);
    }
    return 0;
}