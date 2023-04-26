#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define N 105

char NUM[26]={0};

int newNum(char c)
{
    for(int i=0;i<26;++i){
        if(NUM[i]==c||NUM[i]==c-'a'+'A')return i;
    }
    return -1;
}

int newstrcmp(char* s,char* t)
{
    int n1=strlen(s),n2=strlen(t);
    int i=0,j=0;
    while(i<n1&&j<n2){
        if(newNum(s[i])<newNum(t[i]))return -1;
        else if(newNum(s[i])>newNum(t[i]))return 1;
        else{++i;++j;}
    }
    if(n1>n2)return 1;
    else if(n1<n2)return -1;
    else return 0;

}

int cmp(const void* a,const void* b)
{
    return newstrcmp((char*)a,(char*)b);
}

int main()
{
    int p=101;
    while(p--){
        scanf("%s\n",NUM);
        char all[N]={'\0'};
        gets(all);
        char s[N][25];
        for(int i=0;i<N;++i){
            for(int j=0;j<25;++j)s[i][j]='\0';
        }
        int k=0;
        int pall=0,pi=0,pj=0;
        while(pall<strlen(all)){
            if(all[pall]!=' '&&all[pall])s[pi][pj++]=all[pall];
            else{
                s[pi][pj]='\0';
                pj=0;++pi;
            }
            pall++;
        }
        qsort(s,pi+1,sizeof(s[0]),cmp);
        for(int i=0;i<pi+1;++i)printf("%s%c",s[i],i==pi?'\n':' ');
    }
    return 0;
}

//QWERTYUIOPASDFGHJKLZXCVBNM
