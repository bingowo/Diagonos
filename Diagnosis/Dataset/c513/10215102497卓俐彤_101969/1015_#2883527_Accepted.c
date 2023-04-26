#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define maxstr 500

void Readnumber(char s[],int a[]){
    int j=0;
    for(int i=0;i<strlen(s);i++){
        int num=0;
        while(s[i]!=','&&i<strlen(s)){
            num*=10;
            num+=s[i++]-'0';
        }
        a[j++]=num;
    }
    a[j]=-1;
}

int prime[26]=
{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,91,97};

void ADD(int a[],int b[],int c[]){
    int len1=0,len2=0;
    int i1=0,i2=0;
    while(a[i1++]!=-1)len1++;
    while(b[i2++]!=-1)len2++;
    int i=0,j=0;
    while(len1&&len2){
        c[j++]+=1+a[--len1]+b[--len2];
        if(c[j-1]>=prime[i++]){
            c[j]++;
            c[j-1]-=prime[i-1];
        }
    }
    if(len1-len2){
        if(len1>len2)
            while(len1){
                c[j++]+=1+a[--len1];
                if(c[j-1]>=prime[i++]){
                    c[j]++;
                    c[j-1]-=prime[i-1];
                }
            }
        else while(len2){
            c[j++]+=1+b[--len2];
            if(c[j-1]>=prime[i++]){
                c[j]++;
                c[j-1]-=prime[i-1];
            }
        }
    }
    if(c[j]!=-1)c[j]++;
}


int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        char s[maxstr];
        int a[26];
        scanf("%s",s);
        Readnumber(s, a);
        int b[26];
        scanf("%s",s);
        Readnumber(s, b);
        int c[26];
        for(int j=0;j<26;j++)c[j]=-1;
        ADD(a,b,c);
        int last=26;
        while(c[--last]==-1);
        for(int k=last;k>0;k--)printf("%d,",c[k]);
        printf("%d\n",c[0]);
    }
    return 0;
}
