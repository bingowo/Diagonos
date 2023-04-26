#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    int num[121];int len;
}BIG;

void trans(char* s,BIG b){
    b.len=strlen(s);
    for(int i=0;i<b.len;i++)b.num[i]=s[i]-'0';
}

int cmp(const void *a,const void *b){
    BIG* g1=(BIG*)a,g2=(BIG*)b;
    int t=(g1->len)-(g2->len);
    if(t)return t;
    for(int i=0;i<g1->len;i++){
        if(g1->num[i]<g2->num[i])return -1;
        else if(g1->num[i]>g2->num[i])return 1;
    }
    return 0;
}

int minus(BIG b1,BIG b2,int *s){
    int l1=b1.len,l2=b2.len,l=b1.len;
    int s2[l2];
    for(int i=0;i<l1;i++)s[i]=b1.num[l1-1-i];
    for(int i=0;i<l2;i++)s2[i]=b2.num[l2-1-i];
    for(int i=0;i<l2;i++){
        if(s[i]>=s2[i])s[i]-=s2[i];
        else{
            s[i]+=10;
            s[i+1]--;
            s[i]-=s2[i];
        }
    }
    for(int i=0;i<l1;i++){
        if(s[i]<0){
            s[i]+=10;
            s[i+1]--;
        }
    }
    for(int i=l1-1;i>=0;i--){
        if(s[i]==0)l--;
    }
    return l;
}

int main(){
    int t;
    scanf("%d",&t);
    BIG g[t];
    for(int i=0;i<t;i++){
        char s[121];
        memset(s,0,sizeof(s));
        scanf("%s",s);
        trans(s,g[i]);
    }
    qsort(g,t,sizeof(BIG),cmp);
    int s[121];memset(s,0,sizeof(s));
    int l=minus(g[t-1],g[0],s);
    for(int i=0;i<l;i++)printf("%d",s[i]);
}