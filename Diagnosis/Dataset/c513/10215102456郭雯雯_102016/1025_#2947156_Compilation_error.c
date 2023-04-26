#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct group{
    char s[25];int m;
};

int diff(const char *s,int l){
    int d=l;strcpy(char c[25],s);
    for(int i=0;i<l;i++){
        for(int j=i+1;j<l;j++){
            if(c[j]==c[i]){d--;c[j]=j+'0';}
        }
    }
    return d;
}

int cmp(const void *a,const void *b){
    struct group *g1=(struct group*)a,*g2=(struct group*)b;
    int t=(g2->m)-(g1->m);
    if(t)return t;
    return strcmp(g1->s,g2->s);
}

int main(){
    int t,a=0,n;
    scanf("%d",&t);
    while(a<t){
        scanf("%d",&n);
        struct group g[n];
        for(int i=0;i<n;i++){
            scanf("%s",g[i].s);
            g[i].m=diff(g[i].s,strlen(g[i].s));
        }
        qsort(g,n,sizeof(struct group),cmp);
        printf("case #%d:\n",a);
        for(int i=0;i<n;i++)printf("%s\n",g[i].s);
        a++;
    }
}