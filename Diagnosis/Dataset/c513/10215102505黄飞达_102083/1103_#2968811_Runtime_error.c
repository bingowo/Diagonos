#include<stdio.h>
#include<string.h>

int main(){
    int reg[4]={0};
    char s[10]={};
    while(scanf("%s", s)!=EOF){
        char s2[10]={};
        scanf("%s", s2);
        switch(s[0]){
            case 'I':{
                int num=0;
                for (int i=0; i<strlen(s2); i++){
                    if (s2[i]==',') {
                        for (int j=1; i+j<strlen(s2); j++) {
                            num*=10;
                            num+=s2[i+j]-'0';
                        }
                        break;
                    } 
                }
                reg[s2[0]-'A']=num;
                break;                
            }
            case 'M':
                if (s[1]=='O') reg[s2[0]-'A']=reg[s2[3]-'A'];
                else reg[s2[0]-'A']*=reg[s2[3]-'A'];
                break;
            case 'A':
                reg[s2[0]-'A']+=reg[s2[3]-'A'];
                break;
            case 'S':
                reg[s2[0]-'A']-=reg[s2[3]-'A'];
                break;
            case 'D':
                reg[s2[0]-'A']/=reg[s2[3]-'A'];
                break;
            case 'O':
                printf("%d\n", reg[s2[0]-'A']);
                break;
            default:
                break;
        }
    }
    return 0;
}