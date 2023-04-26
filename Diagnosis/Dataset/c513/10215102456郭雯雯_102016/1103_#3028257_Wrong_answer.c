#include<stdio.h>
#include<string.h>

int main(){
    int num[27]={0};
    char mod[4],ber[15];
    mod[0]='\0';ber[0]='\0';
    while(scanf("%s %s",mod,ber)!=EOF){
        if(strcmp(mod,"IN")==0){
            int l=strlen(ber);
            char n[15];n[0]='\0';
            strncpy(n,ber+3,l-3);
            num[ber[0]-'A']=atoi(n);
        }
    }
}