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
        char s[20],c[20],c1[20],ans[20];
        scanf("%s",s);
        memset(c,0,sizeof(c));memset(ans,0,sizeof(ans));memset(c1,0,sizeof(c1));
        int l=strlen(s),lc=strlen(c);
        for(int i=0;i<l;i++){
            int j=0;
            while(j<lc&&s[i]!=c[j])j++;
            if(j==lc){c[j]=s[i];lc++;}
        }
        lc=strlen(c);
        qsort(c,lc,sizeof(char),cmpc);
        printf("case #%d:\n",a);
        int m=0,n=1;
        while(m<lc){
            strncpy(c1,c+m,lc-m);
            //printf("%s\n",c1);
            int lc1=strlen(c1);
            for(int i=1;i<lc1;i++)
                for(int j=0;j<=lc1-i;j++){
                    printf("%c",c1[0]);
                    strncpy(ans,c1+i,j);
                    printf("%s\n",ans);
                    memset(ans,0,sizeof(ans));
                }
            memset(c1,0,sizeof(c1));
            m++;
        }
        
            
        a++;
    }
}