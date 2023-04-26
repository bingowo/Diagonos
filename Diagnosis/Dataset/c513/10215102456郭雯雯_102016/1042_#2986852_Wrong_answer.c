#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int pow2[20];

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
        for(int i=0;i<lc;i++){//连续
            for(int j=1;j+i-1<lc;j++){
                g[num].l=j;
                strncpy(g[num].str,c+i,j);
                g[num].str[j]='\0';
                num++;
            }
        }
        for(int i=0;i<lc;i++){
            for(int j=i+2;j<lc;j++){
                for(int k=1;k+j-1<lc;k++){
                    g[num].str[0]=c[i];
                    g[num].l=k+1;
                    strncpy(g[num].str+1,c+j,k);
                    g[num].str[k+1]='\0';
                    num++;
                }
            }
        }
        for(int i=0;i<lc;i++){
            for(int j=2;i+j+1<lc;j++){
                for(int k=1;i+j+k<lc;k++){
                    strncpy(g[num].str,c+i,j);
                    strncpy(g[num].str+j,c+i+j+1,k);
                    g[num].l=j+k;
                    g[num].str[j+k]='\0';
                    num++;
                }
            }
        }
        qsort(g,n,sizeof(struct group),cmps);
        printf("case #%d:\n",a);
        for(int i=0;i<n;i++)printf("%s\n",g[i].str);
        a++;
    }
    return 0;
}