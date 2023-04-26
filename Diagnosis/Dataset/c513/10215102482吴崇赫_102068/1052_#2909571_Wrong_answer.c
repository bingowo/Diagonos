#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 25

int findone(char* s)
{
    int cnt=0;
    for(int i=0;i<strlen(s);++i){
        if(s[i]=='O'){cnt++;break;}
    }
    for(int i=0;i<strlen(s);++i){
        if(s[i]=='N'){cnt++;break;}
    }
    for(int i=0;i<strlen(s);++i){
        if(s[i]=='E'){cnt++;break;}
    }
    if(cnt==3)return 1;
    else return 0;
}
int findtwo(char* s)
{
    int cnt=0;
    for(int i=0;i<strlen(s);++i){
        if(s[i]=='T'){cnt++;break;}
    }
    for(int i=0;i<strlen(s);++i){
        if(s[i]=='W'){cnt++;break;}
    }
    for(int i=0;i<strlen(s);++i){
        if(s[i]=='O'){cnt++;break;}
    }
    if(cnt==3)return 1;
    else return 0;
}
int findthree(char* s)
{
    int cnt=0;int sign=0;
    for(int i=0;i<strlen(s);++i){
        if(s[i]=='T'){cnt++;break;}
    }
    for(int i=0;i<strlen(s);++i){
        if(s[i]=='H'){cnt++;break;}
    }
    for(int i=0;i<strlen(s);++i){
        if(s[i]=='E'){cnt++;sign=i+1;break;}
    }
    for(int i=0;i<strlen(s);++i){
        if(s[i]=='R'){cnt++;break;}
    }
    for(int i=sign;i<strlen(s);++i){
        if(s[i]=='E'){cnt++;break;}
    }
    if(cnt==5)return 1;
    else return 0;
}
int findfour(char* s)
{
    int cnt=0;
    for(int i=0;i<strlen(s);++i){
        if(s[i]=='O'){cnt++;break;}
    }
    for(int i=0;i<strlen(s);++i){
        if(s[i]=='F'){cnt++;break;}
    }
    for(int i=0;i<strlen(s);++i){
        if(s[i]=='U'){cnt++;break;}
    }
    for(int i=0;i<strlen(s);++i){
        if(s[i]=='R'){cnt++;break;}
    }
    if(cnt==4)return 1;
    else return 0;
}
int findfive(char* s)
{
    int cnt=0;
    for(int i=0;i<strlen(s);++i){
        if(s[i]=='F'){cnt++;break;}
    }
    for(int i=0;i<strlen(s);++i){
        if(s[i]=='I'){cnt++;break;}
    }
    for(int i=0;i<strlen(s);++i){
        if(s[i]=='V'){cnt++;break;}
    }
    for(int i=0;i<strlen(s);++i){
        if(s[i]=='E'){cnt++;break;}
    }
    if(cnt==4)return 1;
    else return 0;
}
int findsix(char* s)
{
    int cnt=0;
    for(int i=0;i<strlen(s);++i){
        if(s[i]=='S'){cnt++;break;}
    }
    for(int i=0;i<strlen(s);++i){
        if(s[i]=='I'){cnt++;break;}
    }
    for(int i=0;i<strlen(s);++i){
        if(s[i]=='X'){cnt++;break;}
    }
    if(cnt==3)return 1;
    else return 0;
}
int findseven(char* s)
{
    int cnt=0;int sign=0;
    for(int i=0;i<strlen(s);++i){
        if(s[i]=='S'){cnt++;break;}
    }
    for(int i=0;i<strlen(s);++i){
        if(s[i]=='N'){cnt++;break;}
    }
    for(int i=0;i<strlen(s);++i){
        if(s[i]=='E'){cnt++;sign=i+1;break;}
    }
    for(int i=sign;i<strlen(s);++i){
        if(s[i]=='E'){cnt++;break;}
    }
    for(int i=0;i<strlen(s);++i){
        if(s[i]=='V'){cnt++;break;}
    }
    if(cnt==5)return 1;
    else return 0;
}
int findeight(char* s)
{
    int cnt=0;
    for(int i=0;i<strlen(s);++i){
        if(s[i]=='I'){cnt++;break;}
    }
    for(int i=0;i<strlen(s);++i){
        if(s[i]=='H'){cnt++;break;}
    }
    for(int i=0;i<strlen(s);++i){
        if(s[i]=='G'){cnt++;break;}
    }
    for(int i=0;i<strlen(s);++i){
        if(s[i]=='T'){cnt++;break;}
    }
    for(int i=0;i<strlen(s);++i){
        if(s[i]=='E'){cnt++;break;}
    }
    if(cnt==5)return 1;
    else return 0;
}
int findnine(char* s)
{
    int cnt=0;int sign=0;
    for(int i=0;i<strlen(s);++i){
        if(s[i]=='I'){cnt++;break;}
    }
    for(int i=0;i<strlen(s);++i){
        if(s[i]=='N'){cnt++;sign=i+1;break;}
    }
    for(int i=0;i<strlen(s);++i){
        if(s[i]=='E'){cnt++;break;}
    }
    for(int i=sign;i<strlen(s);++i){
        if(s[i]=='N'){cnt++;break;}
    }
    if(cnt==4)return 1;
    else return 0;
}
int findzero(char* s)
{
    int cnt=0;
    for(int i=0;i<strlen(s);++i){
        if(s[i]=='Z'){cnt++;break;}
    }
    for(int i=0;i<strlen(s);++i){
        if(s[i]=='R'){cnt++;break;}
    }
    for(int i=0;i<strlen(s);++i){
        if(s[i]=='O'){cnt++;break;}
    }
    for(int i=0;i<strlen(s);++i){
        if(s[i]=='E'){cnt++;break;}
    }
    if(cnt==4)return 1;
    else return 0;
}
void erasechar(char* s,char c)
{
    char temp[N]={'\0'};
    strcpy(temp,s);
    for(int i=0;i<strlen(s);++i)s[i]='\0';
    int pt=0,ps=0,flag=1;
    while(pt<strlen(temp)){
        if(flag&&temp[pt]==c){flag=0;pt++;}
        else s[ps++]=temp[pt++];
    }
    s[ps]='\0';
    //printf("%d",strlen());
}

void eraseone(char* s)
{
    erasechar(s,'O');
    erasechar(s,'N');
    erasechar(s,'E');
}

void erasetwo(char* s)
{
    erasechar(s,'T');
    erasechar(s,'W');
    erasechar(s,'O');
}
void erasethree(char* s)
{
    erasechar(s,'T');
    erasechar(s,'H');
    erasechar(s,'R');
    erasechar(s,'E');
    erasechar(s,'E');
}
void erasefour(char* s)
{
    erasechar(s,'O');
    erasechar(s,'F');
    erasechar(s,'R');
    erasechar(s,'U');
}
void erasefive(char* s)
{
    erasechar(s,'F');
    erasechar(s,'I');
    erasechar(s,'V');
    erasechar(s,'E');
}
void erasesix(char* s)
{
    erasechar(s,'S');
    erasechar(s,'I');
    erasechar(s,'X');
}
void eraseseven(char* s)
{
    erasechar(s,'S');
    erasechar(s,'E');
    erasechar(s,'V');
    erasechar(s,'N');
    erasechar(s,'E');
}
void eraseeight(char* s)
{
    erasechar(s,'I');
    erasechar(s,'G');
    erasechar(s,'H');
    erasechar(s,'T');
    erasechar(s,'E');
}
void erasenine(char* s)
{
    erasechar(s,'N');
    erasechar(s,'I');
    erasechar(s,'N');
    erasechar(s,'E');
}
void erasezero(char* s)
{
    erasechar(s,'Z');
    erasechar(s,'O');
    erasechar(s,'R');
    erasechar(s,'E');
}
int main()
{
    int T;scanf("%d\n",&T);
    for(int i=0;i<T;++i){
    char input[N]={'\0'};char ret[N]={'\0'};
    scanf("%s",input);
    //eraseone(input);
    //printf("%s",input);
    int p=0;
    int one=0,two=0,three=0,four=0,five=0,six=0,seven=0,eight=0,nine=0,zero=0;
    while(findzero(input)){zero++;erasezero(input);}
    while(findone(input)){one++;eraseone(input);}
    while(findtwo(input)){two++;erasetwo(input);}
    while(findthree(input)){three++;erasethree(input);}
    while(findfour(input)){four++;erasefour(input);}
    while(findfive(input)){five++;erasefive(input);}
    while(findsix(input)){six++;erasesix(input);}
    while(findseven(input)){seven++;eraseseven(input);}
    while(findeight(input)){eight++;eraseeight(input);}
    while(findnine(input)){nine++;erasenine(input);}
    while(zero--)ret[p++]='0';
    while(one--)ret[p++]='1';
    while(two--)ret[p++]='2';
    while(three--)ret[p++]='3';
    while(four--)ret[p++]='4';
    while(five--)ret[p++]='5';
    while(six--)ret[p++]='6';
    while(seven--)ret[p++]='7';
    while(eight--)ret[p++]='8';
    while(nine--)ret[p++]='9';
    printf("case #%d:\n",i);
    printf("%s\n",ret);}
    return 0;
}
