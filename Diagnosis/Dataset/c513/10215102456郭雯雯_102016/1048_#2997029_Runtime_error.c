#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct group{
    int xi,ci;
};

struct group trans(char *s){
    int l=strlen(s),n,i=0;
    struct group g;
    if(s[0]=='-'){n=-1;i++;}
    else if(s[0]=='+'){n=1;i++;}
    else n=1;
    char s0[101];
    int m=0;
    while(s[m]!='x')m++;
    if(m==0)g.xi=1;
    else if(m==i)g.xi=n*1;
    else{
        strncpy(s0,s+i,m-i);
        s0[m-i]='\0';
        g.xi=atoi(s0);
        g.xi*=n;
    }
    if(m==l-1)g.ci=1;
    else if(s[m+1]=='^'){
        strncpy(s0,s+m+2,l-m-2);
        s0[l-m-2]='\0';
        g.ci=atoi(s0);
    }
    return g;
}

int main(){
    char s1[101],s2[101];
    while(scanf("%s %s",s1,s2)!=EOF){
        int l1=strlen(s1),l2=strlen(s2);
        int a[50],b[50];
        a[0]=0;b[0]=0;
        int m=1,n=1;
        for(int i=1;i<l1;i++){
            if(s1[i]=='+'||s1[i]=='-')a[m++]=i;
        }
        a[m]=l1;
        for(int i=0;i<l2;i++){
            if(s2[i]=='+'||s2[i]=='-')b[n++]=i;
        }
        b[n]=l2;
        struct group g1[m+1],g2[n+1];
        for(int i=0;i<m;i++){
            char s0[101];
            strncpy(s0,s1+a[i],a[i+1]-a[i]);
            s0[a[i+1]-a[i]]='\0';
            g1[i].xi=trans(s0).xi;g1[i].ci=trans(s0).ci;
        }
        for(int i=0;i<n;i++){
            char s0[101];
            strncpy(s0,s1+b[i],b[i+1]-b[i]);
            s0[b[i+1]-b[i]]='\0';
            g2[i].xi=trans(s0).xi;g2[i].ci=trans(s0).ci;
        }
        
    }
}