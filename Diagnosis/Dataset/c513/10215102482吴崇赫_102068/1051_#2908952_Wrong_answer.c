#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define N 1005  // the max length of string

char* transBit(char c)
{
    char* ret=(char*)malloc(9);
    for(int i=0;i<9;++i)ret[i]='\0';
    int n=c;int p=7;
    while(n){
        if(n%2)ret[p--]='1';
        else ret[p--]='0';
        n/=2;
    }
    while(p>-1)ret[p--]='0';
    return ret;
}

char* binstring(char* s)
{
    int n=strlen(s);
    char* ret=(char*)malloc(N);
    for(int i=0;i<N;++i)ret[i]='\0';
    for(int i=0;i<n;++i){
        strcat(ret,transBit(s[i]));
    }
    return ret;
}



int main()
{
    char mirro[65]={'\0'};int cnt=0;
    for(int i='A';i<='Z';++i)mirro[cnt++]=i;
    for(int i='a';i<='z';++i)mirro[cnt++]=i;
    for(int i='0';i<='9';++i)mirro[cnt++]=i;
    mirro[cnt++]='+';mirro[cnt]='\\';
    int T;scanf("%d\n",&T);
    for(int i=0;i<T;++i){
    char s[N]={0};char temp[N]={0};
    scanf("%s",s);
    //printf("%s",binstring(s));
    strcpy(temp,binstring(s));
    while(strlen(temp)%6!=0)strcat(temp,"0");
    //printf("%s",temp);
    int p=0;int a[N]={-1};int pa=0; //pa->a
    while(p<strlen(temp)){
        int sum=0;
        for(int i=p;i<p+6;++i){
            sum*=2;
            sum+=temp[i]-'0';
        }
        a[pa++]=sum;
        p+=6;
    }
    //printf("%d",a[0]);
    char ret[N]={0};int pret=0;// pret->ret
    for(int j=0;j<pa;++j)ret[pret++]=mirro[a[j]];
    while(strlen(ret)%4!=0)strcat(ret,"=");
    printf("case #%d:\n",i);
    printf("%s",ret);}
    return 0;
}
