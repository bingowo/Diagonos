#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char s[1000];
    char ID[9]={"$GPRMC"};
    char end[5]={"END"};
    int shi=0,fen=0,miao=0;
    int jg1=0,jg2=0,jg3=0;
    while(1){
        scanf("%s",s);
        shi=0,fen=0,miao=0;
        if(strcmp(end,s)==0) break;
        int i=0;
        int wei1=0,wei2=0;
        for(;s[i]!=',';i++){
            if(s[i]!=ID[i]) break;
            if(s[i]=='$') wei1=i;
        }
        if(s[i]!=',') continue;
        int jiao=(int)s[wei1+1];
        for(int j=wei1+2;j<=i;j++) {
                jiao=jiao^s[j];}
        i++;
        for(int k=0;s[i]!='.';i++,k++){
            jiao=jiao^s[i];
            if(k<=1) shi=shi*10+s[i]-'0';
            else if(k<=3) fen=fen*10+s[i]-'0';
            else miao=miao*10+s[i]-'0';
        }
        for(;s[i]!='*';i++) jiao=jiao^s[i];
        wei2=i;
        char jy[3];
        jy[0]=s[++i];
        jy[1]=s[++i];
        jy[2]=0;
        int jiaoyan=0;
        jiao=jiao%65536;
        sscanf(jy,"%x",&jiaoyan);
        if(jiao==jiaoyan) {
            jg1=shi;
            jg2=fen;
            jg3=miao;
        }
    }
    jg1=(jg1+8)%24;
    if(jg1<10) printf("0%d:",jg1);
    else printf("%d:",jg1);
    if(jg2<10) printf("0%d:",jg2);
    else printf("%d:",jg2);
    if(jg3<10) printf("0%d\n",jg3);
    else printf("%d\n",jg3);
    return 0;
}
