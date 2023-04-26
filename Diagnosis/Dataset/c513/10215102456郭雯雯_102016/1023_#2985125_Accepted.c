#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct group{
    char word[35];int l;
};

int cmpa(const void *a,const void *b){
    struct group *g1=(struct group *)a,*g2=(struct group *)b;
    return strcmp(g1->word,g2->word);
}

int cmpn(const void *a,const void *b){
    struct group *g1=(struct group *)a,*g2=(struct group *)b;
    int n1=0,n2=0,m=0,n=0;
    char num1[35],num2[35];
    memset(num1,0,sizeof(num1));memset(num2,0,sizeof(num2));
    for(int i=0;i<g1->l;i++){
        if(isdigit(g1->word[i]))num1[m++]=g1->word[i];
    }
    n1=atoi(num1);
    for(int i=0;i<g2->l;i++){
        if(isdigit(g2->word[i]))num2[n++]=g2->word[i];
    }
    n2=atoi(num2);
    if(n1==n2)return strcmp(g1->word,g2->word);
    return n1-n2;
}

int main(){
    struct group g[110],ga[110],gn[110];
    int m=0,a=0,n=0;
    while(scanf("%s",&g[m].word)!=EOF){
        g[m].l=strlen(g[m].word);
        m++;
    }
    for(int i=0;i<m;i++)
        for(int j=0;j<g[i].l;j++){
            if(isdigit(g[i].word[j])){
                strcpy(gn[n].word,g[i].word);
                gn[n].l=g[i].l;
                n++;
                break;
            }
            else if(j==g[i].l-1){
                strcpy(ga[a].word,g[i].word);
                ga[a].l=g[i].l;
                a++;
            }
        }
    qsort(ga,a,sizeof(struct group),cmpa);
    qsort(gn,n,sizeof(struct group),cmpn);
    for(int i=0;i<a;i++)printf("%s ",ga[i].word);
    for(int i=0;i<n;i++)printf("%s ",gn[i].word);
}