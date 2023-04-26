#include<stdio.h>
#include<string.h>

int main(){
    long long num[27]={0};
    char mod[4],ber[15];
    mod[0]='\0';ber[0]='\0';
    while(scanf("%s %s",mod,ber)!=EOF){
        if(strcmp(mod,"IN")==0){
            int l=strlen(ber);
            char n[15];n[0]='\0';
            if(ber[3]=='-'){
                strncpy(n,ber+4,l-4);
                num[ber[0]-'A']=atoi(n)*(-1);
            }
            else{
                strncpy(n,ber+3,l-3);
                num[ber[0]-'A']=atoi(n);
            }
        }
        else if(strcmp(mod,"MOV")==0){
            num[ber[0]-'A']=num[ber[3]-'A'];
        }
        else if(strcmp(mod,"ADD")==0){
            num[ber[0]-'A']+=num[ber[3]-'A'];
        }
        else if(strcmp(mod,"SUB")==0){
            num[ber[0]-'A']-=num[ber[3]-'A'];
        }
        else if(strcmp(mod,"MUL")==0){
            num[ber[0]-'A']*=num[ber[3]-'A'];
        }
        else if(strcmp(mod,"DIV")==0){
            num[ber[0]-'A']/=num[ber[3]-'A'];
        }
        else if(strcmp(mod,"OUT")==0){
            printf("%d\n",num[ber[0]-'A']);
        }
        mod[0]='\0';ber[0]='\0';
    }
}