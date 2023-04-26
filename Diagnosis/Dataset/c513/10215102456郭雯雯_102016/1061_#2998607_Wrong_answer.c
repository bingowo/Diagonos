#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct group{
    char s[16];unsigned long long num;
};

unsigned long long trans(char* s,int n){
    int l=strlen(s);
    unsigned long long num=0;
    for(int i=0;i<l;i++){
        num*=n;
        if(s[i]>='a')num+=(s[i]-'a'+10);
        else num+=(s[i]-'0');
    }
    return num;
}

int cmp(const void *a,const void *b){
    struct group *g1=(struct group*)a,*g2=(struct group*)b;
    long long t=(g1->num)-(g2->num);
    if(t>0)return 1;
    else if(t<0)return -1;
    return strcmp(g1->s,g2->s);
}

int main(){
    int t;
    scanf("%d",&t);
    char r[16]="023456789abcdef";
    struct group *g=(struct group *)malloc(sizeof(struct group)*t);
    for(int i=0;i<t;i++){memset(g[i].s,0,sizeof(g[i].s));g[i].num=0;}
    for(int i=0;i<t;i++){
        scanf("%s",g[i].s);
        char s0[16],s[16];
        memset(s,0,sizeof(s));memset(s0,0,sizeof(s0));
        strcpy(s0,g[i].s);
        int l=strlen(s0),n=0;
        s[0]='1';
        for(int j=1;j<l;j++){
            int k;
            for(k=0;k<j;k++){
                if(s0[j]==s0[k]){s[j]=s[k];break;}
            }
            if(k==j)s[j]=r[n++];
        }
        g[i].num=trans(s,n+1);
        //printf("%s %d\n",s,g[i].num);
    }
    qsort(g,t,sizeof(struct group),cmp);
    for(int i=0;i<t;i++)printf("%s\n",g[i].s);
    free(g);
}