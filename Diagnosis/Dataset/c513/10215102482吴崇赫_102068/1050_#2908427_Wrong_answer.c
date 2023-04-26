#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define N 85  // the max length of string

int leftfind(char* s,char* t) // find the minimal index of t in s
{
    int n=strlen(s);int ret=-1;
    if(strlen(t)>n)return -1;
    int ps=0,pt=0; // pointer of s and t
    while(ps<n){
        if(s[ps]==t[pt]){
            ++pt;
            if(pt==strlen(t)){ret=ps;break;}
            ++ps;
        }
        else ps++;
    }
    return ret;
}

int rightfind(char* s,char* t) // find the max index of t in s
{
    int n=strlen(s),m=strlen(t);
    if(m>n)return -1;
    int ret=-1;
    int ps=n-1,pt=m-1; // pointer of s and t
    while(ps>-1){
        if(s[ps]==t[pt]){
            --pt;
            if(pt==-1){ret=ps;break;}
            --ps;
        }
        else ps--;
    }
    return ret;
}

int main()
{
    int T;
    scanf("%d\n",&T);
    for(int i=0;i<T;++i){
        char target[N]={0};char s[N]={0};char t[N]={0};
        scanf("%s%s%s",s,t,target);
        printf("case #%d:\n",i);
        int ret;
        int l=leftfind(target,s);
        int r=rightfind(target,t);
        if(l==-1||r==-1)ret=0;
        else if(l==-1&&r==-1)ret=0;
        else{if(r<l)ret=r+strlen(target)-l;
        else if(l==r)ret=0;
        else ret=r-l-1;}
        printf("%d\n",ret);
    }

    return 0;
}
