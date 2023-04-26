#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct group{
    char s[25];int m;
};

int diff(char *s,int l){
    int d=l;
    for(int i=0;i<l;i++){
        for(int j=i+1;j<l;j++){
            if(s[j]==s[i]){d--;s[j]=j+'0';}
        }
    }
    return d;
}

int cmp(const void *a,const void *b){
    struct group *g1=(struct group*)a,*g2=(struct group*)b;
    int t=(g1->m)-(g2->m);
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