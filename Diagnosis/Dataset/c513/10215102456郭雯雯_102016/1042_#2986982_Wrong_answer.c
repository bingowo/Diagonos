#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int pow2[20];

struct group{
    char str[20],sort[20];
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

int check(char *c){
    int l=strlen(c);
    for(int i=0;i<l-1;i++){
        if(c[i]=='1'&&c[i+1]=='0')return i+1;
    }
    return 0;
}

int main(){
    pow2[0]=1;
    for(int i=1;i<20;i++)pow2[i]=2*pow2[i-1];
    int t,a=0;
    scanf("%d",&t);
    while(a<t){
        char s[20],c[20];
        memset(s,0,sizeof(s));memset(c,0,sizeof(c));
        scanf("%s",s);
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
        for(int i=0;i<n;i++){
            memset(g[i].str,0,sizeof(g[i].str));
            memset(g[i].sort,0,sizeof(g[i].sort));
        }
        for(int i=1;i<=lc;i++){
            char zo[20];
            for(int j=0;j<i;j++)zo[j]='1';
            for(int j=i;j<lc;j++)zo[j]='0';
            zo[lc]='\0';
            strcpy(g[num].sort,zo);
            g[num].sort[lc]='\0';
            num++;
            while(check(zo)){
                int m=check(zo);
                zo[m]='1';zo[m-1]='0';
                strcpy(g[num].sort,zo);
                g[num].sort[lc]='\0';
                num++;
            }
        }
        for(int i=0;i<n;i++){
            int m=0;
            for(int j=0;j<lc;j++){
                if(g[i].sort[j]=='1')g[i].str[m++]=c[j];
            }
            g[i].str[m]='\0';
        }
        qsort(g,n,sizeof(struct group),cmps);
        printf("case #%d:\n",a);
        for(int i=0;i<n;i++)printf("%s\n",g[i].str);
        a++;
        
    }
    return 0;
}