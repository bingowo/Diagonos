#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmpc(const void *a,const void *b){
    char c=*(char*)a,d=*(char*)b;
    int t=c-d;
    return t;
}

int main(){
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
        printf("case #%d:\n",a);
        for(int i=0;i<lc;i++){
            printf("%c",c[i]);
            for(int m=i;m<lc;m++){
                if(m>i){
                    for(int j=0;j<lc-m;j++){
                        for(int k=m;k<=m+j;k++){
                            printf("%c",c[k]);
                            if(k==m+j)printf('\n');
                        }
                    }
                }
            }
            
        }
        a++;
    }
}