#include<stdio.h>
#include<string.h>
#include<ctype.h>

int R[26];
struct Group{
    char word[21];int l;
}G[101];

int main(){
    char r[27],s[2100];
    int space[100];
    memset(r,0,sizeof(r));memset(s,0,sizeof(s));
    while(gets(r)){
        gets(s);
        for(int i=0;i<100;i++)space[i]=0;
        for(int i=0;i<26;i++)R[i]=0;//初始化
        for(int i=0;i<26;i++)
            R[s[i]-'A']=i;
        int len=strlen(s);
        memset(r,0,sizeof(r));memset(s,0,sizeof(s));
    }
}