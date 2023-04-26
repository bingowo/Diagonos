#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct group{
    int xi,ci;
};

void trans(char *s,struct group g){
    int l=strlen(s),n,i=0;
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
}

int main(){
    char s1[101],s2[101];
    while(scanf("%s %s",s1,s2)!=EOF){
        int l1=strlen(s1),l2=strlen(s2);
        int a[50],b[50];
        a[0]=0;b[0]=0;
        int m=1,n=1;
        for(int i=0;i<l1;i++){
            if(s1[i]=='+'||s1[i]=='-')a[m++]=i;
        }
        a[m]=l1;
        for(int i=0;i<l2;i++){
            if(s2[i]=='+'||s2[i]=='-')b[n++]=i;
        }
        b[n]=l2;
        struct group g1[m],g2[n];
        for(int i=0;i<m;i++){
            char s0[101];
            strncpy(s0,s1+a[i],a[i+1]-a[i]);
            s0[a[i+1]-a[i]]='\0';
            trans(s0,g1[i]);
        }
        for(int i=0;i<m;i++)printf("%d ",g[i].xi);
    }
}