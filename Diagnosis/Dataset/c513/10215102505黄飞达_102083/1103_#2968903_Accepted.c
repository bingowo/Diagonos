#include<stdio.h>
#include<string.h>

int main(){
    long long reg[4]={0};
    char s[30]={0}, b[30]={0};
    while(scanf("%s", s)!=EOF){
        scanf("%s", b);
        switch(s[0]){
            case 'I':{
                long long num=0, fuhao=1;
                for (int i=3;i<strlen(b);i++){
                    if (b[i]=='-'){fuhao=-1;continue;}
                    num*=10;
                    num+=b[i]-'0';
                }
                reg[b[0]-'A']=num*fuhao;
                break;                
            }
            case 'M':
                if (s[1]=='O') reg[b[0]-'A']=reg[b[3]-'A'];
                else reg[b[0]-'A']*=reg[b[3]-'A'];
                break;
            case 'A':
                reg[b[0]-'A']+=reg[b[3]-'A'];
                break;
            case 'S':
                reg[b[0]-'A']-=reg[b[3]-'A'];
                break;
            case 'D':
                reg[b[0]-'A']/=reg[b[3]-'A'];
                break;
            case 'O':
                printf("%lld\n", reg[b[0]-'A']);
                break;
            default:
                break;
        }
    }
    return 0;
}