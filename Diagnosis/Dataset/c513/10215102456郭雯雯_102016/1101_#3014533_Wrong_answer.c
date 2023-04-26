#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    char s[2],c;
}group;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        char sf[3],sm[3],sc[3];
        scanf("%s %s %s",sf,sm,sc);
        int lf=strlen(sf),lm=strlen(sm),lc=strlen(sc);
        if(lc==1){
            group f,m,c[8];
            f.c=sf[lf-1];m.c=sf[lm-1];
            strncpy(f.s,sf,lf-1);strncpy(m.s,sm,lm-1);
        }
    }
}