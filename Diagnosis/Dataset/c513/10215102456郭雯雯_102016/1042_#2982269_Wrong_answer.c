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
        char s[20],c[20],ans[20];
        scanf("%s",s);
        memset(c,0,sizeof(c));memset(ans,0,sizeof(ans));
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
            for(int j=i+1;j<lc;j++)
                for(int k=1;k<=lc-j;k++){
                    strncpy(ans,c+j,k);
                    printf("%s\n",ans);
                    memset(ans,0,sizeof(ans));
                }
        }    
            
        a++;
    }
}