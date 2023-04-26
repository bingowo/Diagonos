#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct group{
    int xi,ci;
};

struct group trans(char *s){
    int l=strlen(s),x=0,n=1,i=0;//x记录x位置,n为x前系数正负
    struct group g;
    while(s[x]!='x'&&x<l)x++;
    if(x==l)g.ci=0;
    else if(x==0)g.xi=1;
    if(s[0]=='-'){n=-1;i++;}
    else if(s[0]=='+'){n=1;i++;}
    char num[101];memset(num,0,sizeof(num));
    if(i==x)g.xi=n;
    else{
        strncpy(num,s+i,x-i);
        num[x-i]='\0';
        g.xi=atoi(num);
        g.xi*=n;
    }
    if(x==l)g.ci==0;
    else if(x=l-1)g.ci=1;
    else{
        int y=x+2;
        memset(num,0,sizeof(num));
        strncpy(num,s+y,l-y);
        num[l-y]='\0';
        g.ci=atoi(num);
    }
    return g;
}

int main(){
    char s1[101],s2[101];
    memset(s1,0,sizeof(s1));memset(s2,0,sizeof(s2));
    while(scanf("%s %s",s1,s2)!=EOF){
        int l1=strlen(s1),l2=strlen(s2);
        int a[55],b[55];
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
            char s0[101];memset(s0,0,sizeof(s0));
            strncpy(s0,s1+a[i],a[i+1]-a[i]);
            s0[a[i+1]-a[i]]='\0';
            //printf("%s\n",s0);
            g1[i].xi=trans(s0).xi;g1[i].ci=trans(s0).ci;
        }
        for(int i=0;i<n;i++){
            char s0[101];memset(s0,0,sizeof(s0));
            strncpy(s0,s2+b[i],b[i+1]-b[i]);
            s0[b[i+1]-b[i]]='\0';
            //printf("%s\n",s0);
            g2[i].xi=trans(s0).xi;g2[i].ci=trans(s0).ci;
        }
        for(int i=0;i<m;i++)printf("%d %d\n",g1[i].xi,g1[i].ci);
        memset(s1,0,sizeof(s1));memset(s2,0,sizeof(s2));
    }
}