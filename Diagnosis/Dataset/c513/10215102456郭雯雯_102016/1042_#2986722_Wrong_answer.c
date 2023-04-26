#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int pow2[17];

struct group{
    char str[20];int l;
};

int cmpc(const void *a,const void *b){
    char c=*(char*)a,d=*(char*)b;
    int t=c-d;
    return t;
}

int cmps(const void *a,const void *b){
    struct group *g1=(struct group*)a,*g2=(struct group*)b;
    return strcmp(g1->str,g2->str);
}

int main(){
    pow2[0]=1;
    for(int i=1;i<17;i++)pow2[i]=2*pow2[i-1];
    int t,a=0;
    scanf("%d",&t);
    while(a<t){
        char s[20],c[20];
        scanf("%s",s);
        memset(c,0,sizeof(c));
        int l=strlen(s),lc=strlen(c);
        for(int i=0;i<l;i++){
            int j=0;
            while(j<lc&&s[i]!=c[j])j++;
            if(j==lc){c[j]=s[i];lc++;}
        }
        lc=strlen(c);
        qsort(c,lc,sizeof(char),cmpc);
        int n=pow2[lc]-1,num=0;
        struct group g[n];
        for(int i=0;i<lc;i++){
            for(int j=1;j+i<=lc;j++)
                strncpy(g[num++].str,c+i,j);
        }
        qsort(g,n,sizeof(struct group),cmps);
        printf("case #%d:\n",a);
        for(int i=0;i<n;i++)printf("%s\n",g[i].str);
        a++;
    }
}