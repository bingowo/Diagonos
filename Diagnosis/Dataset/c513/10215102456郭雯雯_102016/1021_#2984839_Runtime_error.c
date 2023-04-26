#include<stdio.h>
#include<string.h>
#include<ctype.h>

int R[26];
struct Group{
    char word[21];int l;
};

int cmp(const void* a,const void* b){
    struct Group *g1=(struct Group*)a,*g2=(struct Group*)b;
    int l1=g1->l,l2=g2->l;
    for(int i=0;i<l1&&i<l2;i++){
        char c1=g1->word[i],c2=g2->word[i];
        int d1=0,d2=0;
        if(isupper(c1))d1=c1-'A';
        else d1=c1-'a';
        if(isupper(c2))d2=c2-'A';
        else d2=c2-'a';
        if(R[d1]<R[d2])return -1;
        else if(R[d1]>R[d2])return 1;
        if(l1<l2)return -1;
        else return 1;
    }
}

int main(){
    char r[27],s[2100];
    int space[100];//记录空格位置
    memset(r,0,sizeof(r));memset(s,0,sizeof(s));
    while(gets(r)){
        gets(s);
        for(int i=0;i<100;i++)space[i]=0;
        for(int i=0;i<26;i++)R[i]=0;//初始化
        for(int i=0;i<26;i++)R[s[i]-'A']=i;
        int len=strlen(s),m=1;
        space[0]=-1;
        for(int i=0;i<len;i++)
            if(isspace(s[i]))space[m++]=i;
        space[m]=len;//m即为单词个数
        struct Group *G=(struct Group*)malloc(sizeof(struct Group)*m);
        for(int i=0;i<m;i++){
            G[i].l=space[i+1]-space[i]-1;
            strncpy(G[i].word,s+space[i]+1,G[i].l);
        }
        qsort(G,m,sizeof(struct Group),cmp);
        for(int i=0;i<m;i++)printf("%s ",G[i].word);
        printf("\n");
        memset(r,0,sizeof(r));memset(s,0,sizeof(s));
    }
}