#include<stdio.h>
#include<string.h>
int main(){
    static char s[1000001],c,*m1,*m2,k[1000001]={'\0'},p[1000001]={'\0'};
    scanf("%s",s);
    m1=s;
    k[0]=*m1;
    p[0]=*m1;
    m1++;
    int i=1;
    while(*m1){
        if(strchr(p,*m1)==NULL){
            p[i++]=*m1;
        }
        else if(i>strlen(k)){
            char *k1;
            k1=k;
            while(*k1){*k1='\0';k1++;}
            strncpy(k,p,i);
            k1=p;
            m1=m1-strlen(p)+1;
            while(*k1){*k1=0;k1++;}
            p[0]=*m1;
            i=1;
        }
        else{
            char *k1=p;
            m1=m1-strlen(p)+1;
            while(*k1){*k1=0;k1++;}
            p[0]=*m1;
            i=1;
        }
        m1++;
    }
    if(i>strlen(k)){
        char *k1;
        k1=k;
        while(*k1){*k1='\0';k1++;}
        strncpy(k,p,i);
    }
    printf("%s",k);
}
